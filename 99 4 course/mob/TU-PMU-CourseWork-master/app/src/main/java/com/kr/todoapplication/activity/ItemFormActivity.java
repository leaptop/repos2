package com.kr.todoapplication.activity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.kr.todoapplication.R;
import com.kr.todoapplication.model.TodoItem;
import com.kr.todoapplication.persistance.TodoItemRepository;

import java.util.Calendar;
import java.util.Date;

public class ItemFormActivity extends AppCompatActivity {

    private static final String TAG = "ItemFormActivity";

    private TextView databaseIdTextView;
    private EditText headerEditText;
    private EditText contentEditText;
    private CheckBox isImportantCheckBox;
    private CheckBox hasDueDate;
    private DatePicker dueDatePicker;
    Button confirmButton;
    Button cancelButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_item_form);

        databaseIdTextView = findViewById(R.id.if_db_id);
        headerEditText = findViewById(R.id.if_header);
        contentEditText = findViewById(R.id.if_content);
        isImportantCheckBox = findViewById(R.id.if_important);
        hasDueDate = findViewById(R.id.if_use_due_date);
        dueDatePicker = findViewById(R.id.if_date);

        confirmButton = findViewById(R.id.if_create_update_button);
        cancelButton = findViewById(R.id.if_cancel_button);

        long databaseId = getIntent().getLongExtra("item-db-id", -1);

        if (databaseId > -1) populateForm(databaseId);

        confirmButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                saveNewItem();
                finish();
            }
        });

        cancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        hasDueDate.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked)
                    dueDatePicker.setVisibility(View.VISIBLE);
                else
                    dueDatePicker.setVisibility(View.INVISIBLE);

            }
        });
    }

    private void saveNewItem() {

        String header = headerEditText.getText().toString();
        String content = contentEditText.getText().toString();
        boolean isImportant = isImportantCheckBox.isChecked();
        Date dueDate = null;

        if (hasDueDate.isChecked())
            dueDate = getDateFromDatePicker(dueDatePicker);

        TodoItem todoItem = new TodoItem(header, content, isImportant, dueDate);

        String databaseIdString = databaseIdTextView.getText().toString();

        if (!"".equals(databaseIdString)) {
            long databaseId = Long.parseLong(databaseIdString);
            todoItem.setId(databaseId);
        }

        TodoItemRepository.getInstance().persist(todoItem);

        startActivity(new Intent(this, ItemViewerActivity.class));
    }

    private void populateForm(long databaseId) {

        TodoItem todoItem = TodoItemRepository.getInstance().findById(databaseId);

        databaseIdTextView.setText(String.valueOf(todoItem.getId()));
        headerEditText.setText(todoItem.getHeader());
        contentEditText.setText(todoItem.getContent());
        isImportantCheckBox.setChecked(todoItem.isImportant());
        confirmButton.setText("Update");

        if (null != todoItem.getDueTo()) {
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(todoItem.getDueTo());
            dueDatePicker.updateDate(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) - 1, calendar.get(Calendar.DATE));
        }
    }

    private Date getDateFromDatePicker(DatePicker datePicker) {
        int day = datePicker.getDayOfMonth();
        int month = datePicker.getMonth();
        int year = datePicker.getYear();

        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month, day);

        return calendar.getTime();
    }
}
