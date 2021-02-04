package com.kr.todoapplication.activity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.kr.todoapplication.R;
import com.kr.todoapplication.model.TodoItem;
import com.kr.todoapplication.persistance.TodoItemRepository;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setUpReminders();

        Button createButton = findViewById(R.id.m_create_new);
        Button viewAllButton = findViewById(R.id.m_view_all);

        viewAllButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this, ItemViewerActivity.class));
            }
        });

        createButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this, ItemFormActivity.class));
            }
        });
    }


    @Override
    protected void onPostResume() {
        super.onPostResume();
        setUpReminders();
    }

    private void setUpReminders() {

        List<TodoItem> mostImportant = TodoItemRepository.getInstance().findMostImportant();
        LinearLayout reminderLinearLayout = findViewById(R.id.m_reminder);

        for (int i = 1; i < reminderLinearLayout.getChildCount(); i++) {
            ((TextView) reminderLinearLayout.getChildAt(i)).setText("");
        }

        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy", Locale.ROOT);

        for (int i = 0; i < mostImportant.size(); i++) {
            TodoItem currentTodoItem = mostImportant.get(i);

            Date dueDate = currentTodoItem.getDueTo();
            String dueDateString = dueDate == null ? "No date set " : dateFormat.format(dueDate);

            String header = currentTodoItem.getHeader();
            String displayMessage = dueDateString + " : " + header;

            TextView currentTextView = (TextView) reminderLinearLayout.getChildAt(i + 1);
            currentTextView.setText(displayMessage);
        }
    }
}
