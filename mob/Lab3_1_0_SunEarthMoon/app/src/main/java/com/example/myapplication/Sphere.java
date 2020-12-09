package com.example.myapplication;

import android.opengl.GLSurfaceView;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.util.Random;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

class Sphere implements GLSurfaceView.Renderer {
    private FloatBuffer mVertexBuffer;
    public FloatBuffer textureBuffer;

    private int n;

    public Sphere(float R) {
        float i = 0;
        n = 0;
        int dtheta = 15, dphi = 15;

        float DTOR = (float)(Math.PI / 180.0f);

        ByteBuffer byteBuf = ByteBuffer.allocateDirect(5000 * 3 * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        mVertexBuffer = byteBuf.asFloatBuffer();
        byteBuf = ByteBuffer.allocateDirect(5000 * 2 * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        textureBuffer = byteBuf.asFloatBuffer();

        for (int theta = -90; theta <= 90 - dtheta; theta += dtheta) {
            for (int phi = 0; phi <= 360 - dphi; phi += dphi){

                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin(theta*DTOR))*R);

                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.cos(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.sin(phi*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin((theta+dtheta)*DTOR))*R);

                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.cos((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.sin((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin((theta+dtheta)*DTOR))*R);


                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin((phi+dphi)*DTOR))*R);
                mVertexBuffer.put((float)(Math.sin(theta*DTOR))*R);
                n += 4;

                textureBuffer.put((float)(phi/360.0f));
                textureBuffer.put((float)((90+theta)/180.0f));

                textureBuffer.put((float)(phi/360.0f));
                textureBuffer.put((float)((90+theta+dtheta)/180.0f));

                textureBuffer.put((float)((phi+dphi)/360.0f));
                textureBuffer.put((float)((90+theta+dtheta)/180.0f));

                textureBuffer.put((float)((phi+dphi)/360.0f));
                textureBuffer.put((float)((90+theta)/180.0f));

            }
        }
        mVertexBuffer.position(0);
        textureBuffer.position(0);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {

    }

    @Override
    public void onDrawFrame(GL10 gl) {

        gl.glEnable(GL10.GL_BLEND); //разрешить наложение цветов
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA); //алгоритм смешения

        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY); // разрешить массив вершин

        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, mVertexBuffer);
        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
        // также
        for (int i = 0; i < n; i += 4)
            gl.glDrawArrays(GL10.GL_TRIANGLE_FAN, i,4);

        // рендер примитивов из массива
        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);

        gl.glDisable(GL10.GL_BLEND);
    }
}
