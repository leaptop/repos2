package com.kr.todoapplication.activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import com.kr.todoapplication.recycle.ItemViewerAdapter;
import com.kr.todoapplication.R;

public class ItemViewerActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_item_viewer);

        RecyclerView recyclerView = findViewById(R.id.the_recycler_view);
        ItemViewerAdapter adapter = new ItemViewerAdapter(this);
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
    }
}
