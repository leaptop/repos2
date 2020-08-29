package com.example.bugs;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import java.util.List;

public class GameManager extends Thread
{
    public static final int GAME_TIME = 60000; // 1 min

    /**Наша скорость в мс = 10*/
    private static final long FPS = 20;

    /**Объект класса GameView*/
    private GameView view;

    /**Задаем состояние потока*/
    private boolean running = false;

    Bitmap bmp;

    /**Конструктор класса*/
    public GameManager(GameView view) {
        this.view = view;

        bmp = BitmapFactory.decodeResource(view.getResources(), R.drawable.table);
        bmp = Bitmap.createScaledBitmap(bmp, (int)(bmp.getWidth() * 1080 / 1600), (int)(bmp.getHeight() * 2560 / 1920), true);
    }

    /**Задание состояния потока*/
    public void setRunning(boolean run) {
        running = run;
    }

    private void draw(Canvas canvas) {
        List<Bug> bugs = view.getBugs();
        //canvas.drawColor(Color.BLACK);


        for(int i = 0; i < bugs.size(); ++i) {
            if (bugs.get(i) != null && bugs.get(i).isAlive()) {
                bugs.get(i).draw(canvas);
            }
        }

        Paint paint = new Paint();
        paint.setColor(Color.WHITE);
        paint.setTextSize(40);
        canvas.drawText(String.valueOf(view.getScore()), 100, 100, paint);
    }

    /** Действия, выполняемые в потоке */
    @Override
    public void run() {
        long ticksPS = 1000 / FPS;
        long startTime;
        long sleepTime;
        while (running) {
            Canvas c = null;
            startTime = System.currentTimeMillis();
            try {
                c = view.getHolder().lockCanvas();
                synchronized (view.getHolder()) {
                    //view.draw(c);

                    c.drawBitmap(bmp, 0, 0, null);

                    draw(c);
                }
            } finally {
                if (c != null) {
                    view.getHolder().unlockCanvasAndPost(c);
                }
            }
            sleepTime = ticksPS-(System.currentTimeMillis() - startTime);
            try {
                if (sleepTime > 0)
                    sleep(sleepTime);
                else
                    sleep(10);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}