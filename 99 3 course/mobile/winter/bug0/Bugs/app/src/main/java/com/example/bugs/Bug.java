package com.example.bugs;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import java.util.Random;
import android.graphics.Rect;
import android.media.MediaPlayer;

public class Bug implements Runnable{

    private GameView gameView;

    private Bitmap bmp;

    private int x;
    private int y;

    private int xSpeed;
    private int ySpeed;

    private int width;
    private int height;

    private int value;

    private boolean isAlive = false;

    Bug(GameView gameView, int resource, double scale, int speed, int value)
    {
        Bitmap bmp = BitmapFactory.decodeResource(gameView.getResources(), resource);
        bmp = Bitmap.createScaledBitmap(bmp, (int)(bmp.getWidth() * scale), (int)(bmp.getHeight() * scale), true);

        this.gameView = gameView;
        this.bmp = bmp;
        this.width = bmp.getWidth();
        this.height = bmp.getHeight();
        this.value = value;

        Random rnd = new Random();

        switch (rnd.nextInt(2)) {
            case 0:
                xSpeed = speed;
                break;

            case 1:
                xSpeed = -speed;
                break;
        }

        switch (rnd.nextInt(2)) {
            case 0:
                ySpeed = speed;
                break;

            case 1:
                ySpeed = -speed;
                break;
        }

        switch (rnd.nextInt(4)) {
            case 0:
                x = -width;
                y = rnd.nextInt(gameView.getHeight() - height);
                break;

            case 1:
                x = rnd.nextInt(gameView.getWidth() - width);
                y = -height;
                break;

            case 2:
                x = gameView.getWidth();
                y = rnd.nextInt(gameView.getHeight() - height);
                break;

            case 3:
                x = rnd.nextInt(gameView.getWidth() - width);
                y = gameView.getHeight();
                break;
        }
    }

    private void update()
    {
        if (x >= gameView.getWidth() - width) {
            if (xSpeed > 0) {
                xSpeed = -xSpeed;
            }
        }
        else {
            if (x <= 0) {
                if (xSpeed < 0) {
                    xSpeed = -xSpeed;
                }
            }
        }

        x = x + xSpeed;

        if (y >= gameView.getHeight() - height) {
            if (ySpeed > 0) {
                ySpeed = -ySpeed;
            }
        }
        else {
            if (y <= 0) {
                if (ySpeed < 0) {
                    ySpeed = -ySpeed;
                }
            }
        }

        y = y + ySpeed;
    }

    boolean isCollision(float x2, float y2) {
        return x2 > x && x2 < x + width && y2 > y && y2 < y + height;
    }

    void draw(Canvas canvas)
    {
        int srcX = 0;
        int srcY = 0;
        Rect src = new Rect(0, 0, srcX + width, srcY + height);
        Rect dst = new Rect(x, y, x + width, y + height);
        canvas.drawBitmap(bmp, src, dst, null);
    }

    boolean isAlive() {
        return isAlive;
    }

    void setAlive(boolean statue) {
        isAlive = statue;
    }

    int getValue() {
        return value;
    }

    @Override
    public void run() {
        isAlive = true;

        while (isAlive) {
            update();

            try {
                Thread.sleep(1000 / 30);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
