package ru.example.database;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public static final int colNum = 5;

    private SQLiteDatabase db;
    private StudentsDB dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dbHelper = new StudentsDB(MainActivity.this);
        db = dbHelper.getWritableDatabase();

        TableLayout table = findViewById(R.id.bd_table);

        TableRow tablehead = new TableRow(this);
        tablehead.setPadding(2, 0, 10, 0);

        TextView htv1 = new TextView(this);
        htv1.setText("№");
        tablehead.addView(htv1);

        TextView htv2 = new TextView(this);
        htv2.setText("Имя");
        tablehead.addView(htv2);

        TextView htv3 = new TextView(this);
        htv3.setText("Вес");
        tablehead.addView(htv3);

        TextView htv4 = new TextView(this);
        htv4.setText("Рост");
        tablehead.addView(htv4);

        TextView htv5 = new TextView(this);
        htv5.setText("Возраст");
        tablehead.addView(htv5);
        table.addView(tablehead);

        Cursor c;


        c = db.rawQuery("SELECT * FROM StudTable3 ORDER BY age ASC", null);

        if(c.moveToFirst()) {
            do {
                TableRow tr = new TableRow(this);
                tr.setPadding(2, 0, 10, 0);


                int index = c.getColumnIndex("_id");
                TextView Id_label = new TextView(this);
                Id_label.setPadding(0, 0 ,30 ,0);
                Id_label.setText(c.getString(index));
                tr.addView(Id_label);

                index = c.getColumnIndex("name");
                TextView Name_label = new TextView(this);
                Name_label.setPadding(0, 0 ,30 ,0);
                Name_label.setText(c.getString(index));
                tr.addView(Name_label);

                index = c.getColumnIndex("weight");
                TextView Weight_label = new TextView(this);
                Weight_label.setPadding(0, 0 ,30 ,0);
                Weight_label.setText(c.getString(index));
                tr.addView(Weight_label);

                index = c.getColumnIndex("height");
                TextView Height_label = new TextView(this);
                Height_label.setPadding(0, 0 ,30 ,0);
                Height_label.setText(c.getString(index));
                tr.addView(Height_label);

                index = c.getColumnIndex("age");
                TextView Age_label = new TextView(this);
                Age_label.setText(c.getString(index));
                tr.addView(Age_label);
                tr.setPadding(0, 0, 0, 10);

                table.addView(tr);

            } while(c.moveToNext());
        }
    }
}
