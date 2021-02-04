package com.kr.todoapplication.recycle;

import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.kr.todoapplication.R;
import com.kr.todoapplication.activity.ItemFormActivity;
import com.kr.todoapplication.model.TodoItem;
import com.kr.todoapplication.persistance.TodoItemRepository;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;

public class ItemViewerAdapter extends RecyclerView.Adapter<ItemViewerAdapter.ItemViewHolder> {

    private static final String TAG = "ItemViewerAdapter";

    private Context context;
    private List<TodoItem> todoItems;

    public ItemViewerAdapter(Context context) {
        this.context = context;
        this.todoItems = TodoItemRepository.getInstance().findAll();
    }

    @NonNull
    @Override
    public ItemViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.recycler_item, parent, false);

        return new ItemViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull final ItemViewHolder holder, final int position) {
        Log.d(TAG, "Binding. Position: " + position);

        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy", Locale.ROOT);
        TodoItem currentTodoItem = todoItems.get(position);

        holder.header.setText(currentTodoItem.getHeader());
        holder.content.setText(currentTodoItem.getContent());
        holder.createdDate.setText(dateFormat.format(currentTodoItem.getCreated()));
        Date dueDate = currentTodoItem.getDueTo();
        holder.dueDate.setText(null == dueDate ? "N/A" : dateFormat.format(dueDate));
        holder.databaseIdTextView.setText(String.valueOf(currentTodoItem.getId()));

        if (currentTodoItem.isImportant())
            holder.parentLayout.setBackgroundColor(Color.rgb(240, 173, 173));

        holder.deleteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                deleteItemAt(position);
            }
        });

        holder.parentLayout.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                updateItem(holder);
                return true;
            }
        });
    }

    @Override
    public int getItemCount() {
        return (int) TodoItemRepository.getInstance().totalCount();
    }

    private void deleteItemAt(int position) {
        TodoItem todoItemForDeletion = todoItems.get(position);
        TodoItemRepository.getInstance().delete(todoItemForDeletion);
        todoItems.remove(todoItemForDeletion);

        Log.d(TAG, "Deleted item at: " + position);

        notifyItemRemoved(position);
        notifyItemRangeChanged(position, getItemCount());

        String toastMessage = "Deleted " + todoItemForDeletion.getHeader();
        Toast.makeText(context, toastMessage, Toast.LENGTH_LONG).show();
    }

    private void updateItem(ItemViewHolder holder) {

        long id = Long.parseLong(holder.databaseIdTextView.getText().toString());
        TodoItem todoItem = TodoItemRepository.getInstance().findById(id);

        Log.d(TAG, "Updating item with header: " + todoItem.getHeader());

        Intent updateIntent = new Intent(context, ItemFormActivity.class);
        updateIntent.putExtra("item-db-id", todoItem.getId());

        context.startActivity(updateIntent);
    }


    // view holder class
    static class ItemViewHolder extends RecyclerView.ViewHolder {

        TextView databaseIdTextView;
        RelativeLayout parentLayout;
        ImageView imageView;
        TextView header;
        TextView content;
        ImageView deleteButton;
        TextView createdDate;
        TextView dueDate;

        ItemViewHolder(@NonNull View itemView) {
            super(itemView);
            databaseIdTextView = itemView.findViewById(R.id.ri_db_id);
            parentLayout = itemView.findViewById(R.id.parent_layout);
            imageView = itemView.findViewById(R.id.ri_image);
            header = itemView.findViewById(R.id.ri_text);
            header.setPaintFlags(Paint.UNDERLINE_TEXT_FLAG);
            content = itemView.findViewById(R.id.ri_content);
            deleteButton = itemView.findViewById(R.id.ri_delete_button);
            createdDate = itemView.findViewById(R.id.ri_created_date);
            dueDate = itemView.findViewById(R.id.ri_due_date);
        }
    }
}
