package com.example.bugs;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import java.util.List;

public class GameManager extends Thread
{
    private static final int FPS = 30;

    private GameView view;

    private boolean isAlive = false;

    private Bitmap bmp;

    GameManager(GameView view) {
        this.view = view;

        bmp = BitmapFactory.decodeResource(view.getResources(), R.drawable.table);
        bmp = Bitmap.createScaledBitmap(bmp,1080, 2160, true);
    }

    void setAlive(boolean statue) {
        isAlive = statue;
    }

    private void draw(Canvas canvas) {
        List<Bug> bugs = view.getBugs();

        for(int i = 0; i < bugs.size(); ++i) {
            if (bugs.get(i) != null && bugs.get(i).isAlive()) {
                bugs.get(i).draw(canvas);
            }
        }

        Paint paint = new Paint();
        paint.setColor(Color.BLACK);
        paint.setTextSize(80);
        canvas.drawText(String.valueOf(view.getScore()), 100, 100, paint);
    }

    @Override
    public void run() {
        long ticksPS = 1000 / FPS;
        long startTime;
        long sleepTime;

        while (isAlive) {
            Canvas c = null;
            startTime = System.currentTimeMillis();

            try {
                c = view.getHolder().lockCanvas();
                synchronized (view.getHolder()) {
                    c.drawBitmap(bmp, 0, 0, null);

                    draw(c);
                }
            } finally {
                if (c != null) {
                    view.getHolder().unlockCanvasAndPost(c);
                }
            }

            sleepTime = ticksPS - (System.currentTimeMillis() - startTime);

            try {
                if (sleepTime > 0) {
                    sleep(sleepTime);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}