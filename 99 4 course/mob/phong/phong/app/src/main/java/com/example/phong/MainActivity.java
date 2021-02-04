package com.example.phong;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;
import android.view.MotionEvent;

public class MainActivity extends AppCompatActivity {

    /*float mDownX;
    float mDownY;
    float mLightX = 10f;
    float mLightY = 10f;
    */

    private GLSurfaceView myGLSurfaceView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (!supportES2()) {
            Toast.makeText(this, "OpenGl ES 2.0 is not supported", Toast.LENGTH_LONG).show();
            finish();
            return;
        }
        myGLSurfaceView = new GLSurfaceView(this);
        myGLSurfaceView.setEGLContextClientVersion(2);
        myGLSurfaceView.setRenderer(new MyGL20Renderer(this));
        setContentView(myGLSurfaceView);
    }

/*    @Override
    public boolean onTouchEvent(MotionEvent event) {//обработчик событий
        int action = event.getActionMasked();
        switch (action) {
            case MotionEvent.ACTION_DOWN: //действие вниз
                mDownX = event.getX();
                mDownY = event.getY();
                return true;
            case MotionEvent.ACTION_UP: // действие вверх
                return true;
            case MotionEvent.ACTION_MOVE: // движение
                float mX = event.getX();
                float mY = event.getY();
                mLightX += (mX-mDownX)/10;
                mLightY -= (mY-mDownY)/10;
                mDownX = mX;
                mDownY = mY;
                return true;
            default:
                return super.onTouchEvent(event);
        }
    }*/


    @Override
    protected void onPause() {
        super.onPause();
        myGLSurfaceView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        myGLSurfaceView.onResume();
    }

    private boolean supportES2() {
        ActivityManager activityManager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();
        return (configurationInfo.reqGlEsVersion >= 0x20000);
    }
}