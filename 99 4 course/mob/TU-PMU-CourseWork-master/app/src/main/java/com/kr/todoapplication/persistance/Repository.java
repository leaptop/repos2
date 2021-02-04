package com.kr.todoapplication.persistance;

import com.kr.todoapplication.model.TodoItem;
import com.orm.SugarRecord;

import java.util.List;

public interface Repository<T extends SugarRecord> {
    TodoItem findById(long id);

    long persist(TodoItem todoItem);

    void delete(TodoItem todoItem);

    List<TodoItem> findAll();

    void deleteAll(List<TodoItem> todoItems);

    long totalCount();
}
