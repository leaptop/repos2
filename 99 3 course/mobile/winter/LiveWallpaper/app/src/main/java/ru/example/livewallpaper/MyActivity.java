package ru.example.livewallpaper;

import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.os.Handler;
import android.service.wallpaper.WallpaperService;
import android.view.SurfaceHolder;

public class MyActivity extends WallpaperService {

    public void onCreate()
    {
        super.onCreate();
    }
    public void onDestroy()
    {
        super.onDestroy();
    }
    public Engine onCreateEngine()
    {
        return new MyWallpaperEngine();
    }

    class MyWallpaperEngine extends Engine
    {

        private final Handler handler = new Handler();

        private final Runnable drawRunner = new Runnable() {
            @Override
            public void run() {
                draw();
            }
        };
        private boolean visible = true;

        MyWallpaperEngine()
        {
        }
        public void onCreate(SurfaceHolder surfaceHolder)
        {
            super.onCreate(surfaceHolder);
        }
        @Override
        public void onVisibilityChanged(boolean visible)
        {
            this.visible = visible;

            if (visible)
            {
                handler.post(drawRunner);
            }
            else{
                handler.removeCallbacks(drawRunner);
            }
        }

        @Override
        public void onSurfaceDestroyed(SurfaceHolder holder)
        {
            super.onSurfaceDestroyed(holder);
            this.visible = false;
            handler.removeCallbacks(drawRunner);
        }

        public void onOffsetsChanged(float xOffset, float yOffset, float xStep, float
                yStep, int xPixels, int yPixels)
        {
            handler.post(drawRunner);
        }

        public void draw() {
            final SurfaceHolder holder = getSurfaceHolder();
            Canvas canvas = null;

            try
            {
                canvas = holder.lockCanvas();
                if (canvas != null) {
                    /*
                    canvas.drawColor(Color.BLUE);
                    Paint p=new Paint();
                    p.setColor(Color.RED);
                    canvas.drawText("Hello world",500,500,p);
                                        BatteryManager bm = (BatteryManager)getSystemService(BATTERY_SERVICE);
                    int batLevel = bm.getIntProperty(BatteryManager.BATTERY_PROPERTY_CAPACITY);
                    */
                    IntentFilter ifilter = new IntentFilter(Intent.ACTION_BATTERY_CHANGED);
                    Intent batteryStatus = registerReceiver(null, ifilter);
                    int status = batteryStatus.getIntExtra("level", -1);


                    if (status > 80) {
                        canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery100), 0, 0, null);
                    }
                    else {
                        if (status <= 80 && status > 60 ) {
                            canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.batttery80), 0, 0, null);
                        }
                        else {
                            if (status <= 60 && status > 50 ) {
                                canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery60), 0, 0, null);
                            }
                            else {
                                if (status <= 50 && status > 40) {
                                    canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery50), 0, 0, null);
                                }
                                else {
                                    if (status <= 40 && status > 20) {
                                        canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery40), 0, 0, null);
                                    }
                                    else {
                                        if (status <= 20 && status > 10) {
                                            canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery20), 0, 0, null);
                                        }
                                        else {
                                            if (status <= 10) {
                                                canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery10), 0, 0, null);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }


                    //canvas.drawBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.battery100), 0, 0, null);
                }
            }
            finally
            {
                if (canvas != null)
                    holder.unlockCanvasAndPost(canvas);
            }
            handler.removeCallbacks(drawRunner);
            if (visible)
            {
                handler.postDelayed(drawRunner, 20);
            }
        }
    }
}
