package com.kr.todoapplication.persistance;

import com.kr.todoapplication.model.TodoItem;

import java.util.List;

public class TodoItemRepository implements Repository<TodoItem> {

    private TodoItemRepository() {
    }

    @Override
    public TodoItem findById(long id) {
        return TodoItem.findById(TodoItem.class, id);
    }

    @Override
    public long persist(TodoItem todoItem) {
        return todoItem.save();
    }

    @Override
    public void delete(TodoItem todoItem) {
        todoItem.delete();
    }

    @Override
    public List<TodoItem> findAll() {
        return TodoItem.listAll(TodoItem.class);
    }

    @Override
    public void deleteAll(List<TodoItem> todoItems) {
        TodoItem.deleteInTx(todoItems);
    }

    @Override
    public long totalCount() {
        return TodoItem.count(TodoItem.class, null, null);
    }

    public List<TodoItem> findMostImportant() {
        return TodoItem.findWithQuery(TodoItem.class, "SELECT * FROM TODO_ITEM ORDER BY IS_IMPORTANT DESC, DUE_TO ASC LIMIT 3");
    }

    public static TodoItemRepository getInstance() {
        return LazyHolder.instance;
    }

    private static class LazyHolder {
        static final TodoItemRepository instance = new TodoItemRepository();
    }
}
