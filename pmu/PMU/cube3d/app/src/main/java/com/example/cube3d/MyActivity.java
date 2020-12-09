package com.example.cube3d;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.WindowManager;

public class MyActivity extends Activity {
    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        super.onCreate(savedInstanceState);

        GLSurfaceView g=new GLSurfaceView(this);
        g.setEGLConfigChooser(8,8,8,8,16,1);
        g.setRenderer(new MyRenderer());
        g.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        setContentView(g);
    }
}
