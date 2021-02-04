package com.example.cw003v;

import androidx.appcompat.app.AppCompatActivity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        GLSurfaceView mGLSurfaceView = new GLSurfaceView(this);
        mGLSurfaceView.setEGLContextClientVersion(2);
        MyGl20Renderer renderer = new MyGl20Renderer(this, this);
        mGLSurfaceView.setRenderer(renderer);
        setContentView(mGLSurfaceView);
    }
}
