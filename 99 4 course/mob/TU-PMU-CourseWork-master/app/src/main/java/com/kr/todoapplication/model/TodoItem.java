package com.kr.todoapplication.model;

import com.orm.SugarRecord;

import java.io.Serializable;
import java.util.Date;
import java.util.Objects;

public class TodoItem extends SugarRecord implements Serializable {

    private String header;
    private String content;
    private boolean isImportant;
    private Date created;
    private Date dueTo;

    public TodoItem() {
    }

    public TodoItem(String header, String content, boolean isImportant, Date dueTo) {
        this.header = header;
        this.content = content;
        this.isImportant = isImportant;
        this.created = new Date();
        this.dueTo = dueTo;
    }

    public String getHeader() {
        return header;
    }

    public void setHeader(String header) {
        this.header = header;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public boolean isImportant() {
        return isImportant;
    }

    public void setImportant(boolean important) {
        isImportant = important;
    }

    public Date getCreated() {
        return created;
    }

    public void setCreated(Date created) {
        this.created = created;
    }

    public Date getDueTo() {
        return dueTo;
    }

    public void setDueTo(Date dueTo) {
        this.dueTo = dueTo;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TodoItem todoItem = (TodoItem) o;
        return isImportant == todoItem.isImportant &&
                Objects.equals(header, todoItem.header) &&
                Objects.equals(content, todoItem.content) &&
                Objects.equals(created, todoItem.created) &&
                Objects.equals(dueTo, todoItem.dueTo);
    }

    @Override
    public int hashCode() {
        return Objects.hash(header, content, isImportant, created, dueTo);
    }

    @Override
    public String toString() {
        return "TodoItem{" +
                "header='" + header + '\'' +
                ", body='" + content + '\'' +
                ", isImportant=" + isImportant +
                ", created=" + created +
                ", dueTo=" + dueTo +
                '}';
    }
}
