package com.example.lab2textures00;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.WindowManager;

public class MainActivity extends Activity {
    /**
     * Called when the activity is first created.
     *
     * rendering — «визуализация») — термин в компьютерной графике,
     * обозначающий процесс получения изображения по модели с помощью компьютерной
     * программы. Здесь модель — это описание любых объектов или явлений
     * на строго определённом языке или в виде структуры данных.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        GLSurfaceView g = new GLSurfaceView(this);
        g.setRenderer(new MyRenderer());
        g.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        setContentView(g);
    }
}
