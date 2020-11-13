package com.example.water;


import android.content.Context;
import android.opengl.GLSurfaceView;

//ќпишем наш класс MyClassSurfaceView расшир¤ющий GLSurfaceView
public class MyClassSurfaceView extends GLSurfaceView{
    //создадим ссылку дл¤ хранени¤ экземпл¤ра нашего класса рендерера
    private MyClassRenderer renderer;

    // конструктор
    public MyClassSurfaceView(Context context) {
        // вызовем конструктор родительского класса GLSurfaceView
        super(context);
        setEGLContextClientVersion(2);
        // создадим экземпл¤р нашего класса MyClassRenderer
        renderer = new MyClassRenderer(context);
        // запускаем рендерер
        setRenderer(renderer);
        // установим режим циклического запуска метода onDrawFrame
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        // при этом запускаетс¤ отдельный поток
        // в котором циклически вызываетс¤ метод onDrawFrame
        // т.е. бесконечно происходит перерисовка кадров
    }
}

