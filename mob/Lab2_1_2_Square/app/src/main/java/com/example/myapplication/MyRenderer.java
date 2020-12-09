package com.example.myapplication;

/*//КВАДРАТ
import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
public class MyRenderer implements GLSurfaceView.Renderer {
    float []a=new float[]{
            -1,1,0,
            -1,-1,0,
            1,-1,0,
            1,1,0
    };
    FloatBuffer f;
    ByteBuffer b;
    public MyRenderer(){
        b=ByteBuffer.allocateDirect(4*3*4);
        b.order(ByteOrder.nativeOrder());
        f=b.asFloatBuffer();
        f.put(a);
        f.position(0);
    }
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    }
    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
    }
    @Override
    public void onDrawFrame(GL10 gl) {
        gl.glClearColor(1,1,0,1);
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glTranslatef(0,0,-1);//сдвиг начала системы координат.
        gl.glScalef(0.5f,0.25f,0.5f);
        gl.glColor4f(0,1,1,1);
        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glVertexPointer(3,GL10.GL_FLOAT,0,f);
        gl.glDrawArrays(GL10.GL_TRIANGLE_FAN,0,4);
        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
    }
}*/









//КУБ
import android.opengl.GLES10;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;


import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;



public class MyRenderer implements GLSurfaceView.Renderer {
    MyKube cube;
    float p;

    public MyRenderer(){
        cube=new MyKube();

    }


    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
    }

    @Override
    public void onDrawFrame(GL10 gl) {

        gl.glClearColor(1,1,0,0);

        gl.glClear(GL10.GL_DEPTH_BUFFER_BIT|GL10.GL_COLOR_BUFFER_BIT|GL10.GL_STENCIL_BUFFER_BIT);
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        gl.glEnable(GL10.GL_DEPTH_TEST);
        gl.glOrthof(-10,10, -5,5,5,-5);
        GLU.gluLookAt(gl,0,1,-2,0,2,-1 ,0,1,0);


        gl.glTranslatef(0,3,0);
        gl.glPushMatrix();
        gl.glRotatef(p,0,1,0);
        cube.draw(gl);
        gl.glPopMatrix();


        gl.glEnable(GL10.GL_STENCIL_TEST);
        gl.glStencilFunc(GL10.GL_ALWAYS, 1, 0xFF); // Set any stencil to 1
        gl.glStencilOp(GL10.GL_ZERO, GL10.GL_ZERO, GL10.GL_REPLACE);
        gl.glStencilMask(0xff); // Write to stencil buffer
        gl.glDepthMask(false); // Don't write to depth buffer
        gl.glClearStencil(0);
        gl.glClear(GL10.GL_STENCIL_BUFFER_BIT); // Clear stencil buffer (0 by default)


        gl.glEnable(GL10.GL_STENCIL_TEST);
        gl.glStencilFunc(GL10.GL_EQUAL, 1, 0xFF);
        gl.glStencilMask(0x0);

        gl.glColorMask(true,true,true,true);
        gl.glDepthMask(true);


        gl.glPushMatrix();
        gl.glTranslatef(0,-2,0);
        gl.glRotatef(p,0,1,0);
        cube.draw(gl);
        gl.glPopMatrix();
        p=(p>360)?0:p+1f;


        gl.glDisable(GL10.GL_DEPTH_TEST);
        gl.glDisable(GL10.GL_STENCIL_TEST);
    }
}