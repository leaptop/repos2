package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.WindowManager;
public class MainActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        super.onCreate(savedInstanceState);

        GLSurfaceView g = new GLSurfaceView(this);
        g.setEGLConfigChooser(8, 8, 8, 8, 16, 1);
        g.setRenderer(new MyRenderer());
        g.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        setContentView(g);
    }
}
//    public void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
//        GLSurfaceView g=new GLSurfaceView(this);
//        g.setRenderer(new com.example.myapplication.MyKube());
//        g.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
//        setContentView(g);
//    }
//}


