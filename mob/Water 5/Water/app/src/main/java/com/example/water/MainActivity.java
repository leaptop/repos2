package com.example.water;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

public class MainActivity extends AppCompatActivity {

    // создадим ссылку на экземпляр нашего класса MyClassSurfaceView
    private MyClassSurfaceView mGLSurfaceView;

    // переопределим метод onCreate
    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        //создадим экземпляр нашего класса MyClassSurfaceView
        mGLSurfaceView = new MyClassSurfaceView(this);
        //вызовем экземпляр нашего класса MyClassSurfaceView
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(mGLSurfaceView);
        // на экране появится поверность для рисования в OpenGl ES
    }


    @Override
    protected void onPause() {
        super.onPause();
        mGLSurfaceView.onPause();
    }


    @Override
    protected void onResume() {
        super.onResume();
        mGLSurfaceView.onResume();
    }
}
