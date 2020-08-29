package ru.example.database;

import android.content.Context;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase;
import java.util.Random;

public class StudentsDB extends SQLiteOpenHelper {

    public static final String TABLE_NAME = "StudTable3";

    public StudentsDB(Context context){
        super(context, TABLE_NAME,null,1);
    }

    public void onCreate(SQLiteDatabase db) {
        String[] itemname ={
                "Степан",
                "Егор",
                "Виталий",
                "Анна",
                "Селена",
                "Кристиан",
                "Штирлиц",
                "Татьяна",
                "Феофан"
        };



        db.execSQL("CREATE TABLE " + TABLE_NAME + " (" +
                "_id INTEGER PRIMARY KEY autoincrement, " +
                "name TEXT, " +
                "weight INTEGER, " +
                "height INTEGER, " +
                "age INTEGER );");

        for(int i = 0; i < 20; ++i) {

            String namepath = (itemname[new Random().nextInt(itemname.length)]);
            String st_name = namepath;


            Random rand = new Random();

            Integer randInt = rand.nextInt(10) + 17 ;
            String st_age = randInt.toString();

            randInt = rand.nextInt(40) + 70;
            String st_weight = randInt.toString();

            randInt = rand.nextInt(45) + 150;
            String st_height = randInt.toString();



            db.execSQL("INSERT INTO StudTable3 ('name', 'weight', 'height', 'age') " +
                    "VALUES ('"+ st_name + "', '" + st_weight + "', '" +
                    st_height + "', '" + st_age + "')");

        }
    }

    public void onUpgrade(SQLiteDatabase database, int oldVersion, int newVersion) {
        database.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
        database.execSQL("CREATE TABLE StudTable3 (" +
                "_id INTEGER PRIMARY KEY autoincrement, " +
                "name TEXT, " +
                "weight INTEGER, " +
                "height INTEGER, " +
                "age INTEGER );");
    }
}
