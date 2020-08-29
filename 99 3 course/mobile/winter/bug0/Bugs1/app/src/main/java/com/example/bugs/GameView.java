package com.example.bugs;


import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.CountDownTimer;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.*;

public class GameView extends SurfaceView implements
        SurfaceHolder.Callback {

    private SoundPool soundPool;
    private volatile int score;

    /**объект класса GameView*/
    private GameManager gameLoopThread;

    /**Объект класса Bug*/
    private List<Bug> bugs = new ArrayList<>();
    private Map<String, Integer> sounds = new HashMap<>();

    private Bug createSprite(int resource, double scale) {
        Bitmap bmp = BitmapFactory.decodeResource(getResources(), resource);
        bmp = Bitmap.createScaledBitmap(bmp, (int)(bmp.getWidth() * scale), (int)(bmp.getHeight() * scale), true);

        return new Bug(this, bmp);
    }

    private void createSprites() {
        final Random random = new Random();

        new CountDownTimer(GameManager.GAME_TIME, 1000) {
            @Override
            public void onTick(long millisUntilFinished) {

                switch (random.nextInt(3)) {
                    case 0:
                        Bug bigbug = createSprite(R.drawable.bigbug, 0.2);
                        new Thread(bigbug).start();
                        bugs.add(bigbug);
                        break;

                    case 1:
                        Bug fastbug = createSprite(R.drawable.fastbug, 0.02);
                        new Thread(fastbug).start();
                        bugs.add(fastbug);
                        break;

                    default:
                        Bug fatbug = createSprite(R.drawable.fatbug, 0.13);
                        new Thread(fatbug).start();
                        bugs.add(fatbug);
                }
            }

            @Override
            public void onFinish() {
                for(Bug bug : bugs) {
                    bug.setAlive(false);
                }
            }
        }.start();
    }

    /**Конструктор*/
    public GameView(Context context) {
        super(context);
        gameLoopThread = new GameManager(this);

        /*Рисуем все наши объекты и все все все*/
        getHolder().addCallback(this);

        soundPool = new SoundPool(60, AudioManager.STREAM_MUSIC, 0);
        sounds.put("vil", soundPool.load(context, R.raw.vilgelm, 1));

        score = 0;
    }

    public List<Bug> getBugs() {
        return bugs;
    }

    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();

        if (event.getAction() == MotionEvent.ACTION_DOWN)
            synchronized (getHolder())
            {
                boolean isCatched = false;
                for (int i = bugs.size() - 1; i >= 0; i--)
                {
                    Bug bug = bugs.get(i);

                    if (bug.isCollision(x, y))
                    {
                        ++score;
                        isCatched = true;
                        soundPool.play(1, 100, 100, 1, 0, 1);
                        bug.setAlive(false);
                        bugs.remove(bug);

                        break;
                    }
                }

                if (!isCatched) {
                    --score;
                }
            }

        return true;
    }

    /*** Уничтожение области рисования */
    public void surfaceDestroyed(SurfaceHolder holder) {
        boolean retry = true;
        gameLoopThread.setRunning(false);

        while (retry)
        {
            try
            {
                gameLoopThread.join();
                retry = false;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    /** Создание области рисования */
    public void surfaceCreated(SurfaceHolder holder) {
        createSprites();
        gameLoopThread.setRunning(true);
        gameLoopThread.start();
    }

    /** Изменение области рисования */
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
    }

    public int getScore() {
        return score;
    }
}