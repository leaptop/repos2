package com.example.bugs;

import android.content.Context;
import android.media.AudioAttributes;
import android.media.SoundPool;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.*;

public class GameView extends SurfaceView implements
        SurfaceHolder.Callback {

    private SoundPool soundPool;
    private volatile int score;

    private GameManager gameLoopThread;
    private BugGenerator bugGenerator;


    public volatile List<Bug> bugs = new ArrayList<>();

    public GameView(Context context) {
        super(context);
        gameLoopThread = new GameManager(this);
        bugGenerator = new BugGenerator(this);


        getHolder().addCallback(this);

        AudioAttributes attributes = new AudioAttributes.Builder()
                .setUsage(AudioAttributes.USAGE_GAME)
                .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                .build();


        soundPool = new SoundPool.Builder().setMaxStreams(7).setAudioAttributes(attributes).build();
        soundPool.load(context, R.raw.wood1, 0);
        soundPool.load(context, R.raw.death, 0);

        score = 0;
    }

    public List<Bug> getBugs() {
        return bugs;
    }

    public int getCountBugs() {
        return bugs.size();
    }

    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();

        if (event.getAction() == MotionEvent.ACTION_DOWN)
            synchronized (getHolder())
            {
                boolean isCatched = false;
                for (Bug bug : bugs)
                {
                    if (bug.isCollision(x, y))
                    {
                        isCatched = true;
                        score += bug.getValue();

                        soundPool.play(2, 100, 100, 0, 0, 1);

                        bug.setAlive(false);
                        bugs.remove(bug);

                        break;
                    }
                }

                if (!isCatched) {
                    score -=10;

                    soundPool.play(1, 100, 100, 0, 0, 1);
                }
            }

        return true;
    }


    public void surfaceDestroyed(SurfaceHolder holder) {
        boolean retry = true;
        gameLoopThread.setAlive(false);
        bugGenerator.setAlive(false);

        while (retry)
        {
            try
            {
                gameLoopThread.join();
                bugGenerator.join();
                retry = false;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        soundPool.release();
        soundPool = null;
    }


    public void surfaceCreated(SurfaceHolder holder) {
        gameLoopThread.setAlive(true);
        gameLoopThread.start();

        bugGenerator.setAlive(true);
        bugGenerator.start();
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
    }

    public int getScore() {
        return score;
    }
}