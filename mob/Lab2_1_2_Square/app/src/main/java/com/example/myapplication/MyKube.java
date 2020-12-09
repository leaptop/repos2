package com.example.myapplication;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

public class MyKube {
    private FloatBuffer mVertexBuffer;
    private FloatBuffer mColorBuffer;
    private ByteBuffer  mIndexBuffer;

    private float vertices[] = {
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            -1.0f, 1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f
    };

    private float colors[] = {
            0.0f,  1.0f,  0.0f,  1.0f,
            0.0f,  1.0f,  0.0f,  1.0f,
            1.0f,  0.5f,  0.0f,  1.0f,
            1.0f,  0.5f,  0.0f,  1.0f,
            1.0f,  0.0f,  1.0f,  1.0f,
            1.0f,  0.0f,  0.0f,  1.0f,
            1.0f,  0.0f,  0.0f,  1.0f,
            0.0f,  0.0f,  1.0f,  1.0f,
            1.0f,  0.0f,  1.0f,  1.0f
    };

    private byte indices[] = {
            0, 4, 5, 0, 5, 1,
            1, 5, 6, 1, 6, 2,
            2, 6, 7, 2, 7, 3,
            3, 7, 4, 3, 4, 0,
            4, 7, 6, 4, 6, 5,
            3, 0, 1, 3, 1, 2
    };



    public MyKube() {
        ByteBuffer byteBuf = ByteBuffer.allocateDirect(vertices.length * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        mVertexBuffer = byteBuf.asFloatBuffer();
        mVertexBuffer.put(vertices);
        mVertexBuffer.position(0);

        byteBuf = ByteBuffer.allocateDirect(colors.length * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        mColorBuffer = byteBuf.asFloatBuffer();
        mColorBuffer.put(colors);
        mColorBuffer.position(0);

        mIndexBuffer = ByteBuffer.allocateDirect(indices.length);
        mIndexBuffer.put(indices);
        mIndexBuffer.position(0);
    }

    public void draw(GL10 gl) {
        //gl.glFrontFace(GL10.GL_CW);
        // gl.glEnable(GL10.GL_BACK);

        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, mVertexBuffer);
        gl.glColorPointer(4, GL10.GL_FLOAT, 0, mColorBuffer);

        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glEnableClientState(GL10.GL_COLOR_ARRAY);

        gl.glDrawElements(GL10.GL_TRIANGLES, 36, GL10.GL_UNSIGNED_BYTE,
                mIndexBuffer);


        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glDisableClientState(GL10.GL_COLOR_ARRAY);
        // gl.glDisable(GL10.GL_CULL_FACE);
    }




}

//
//import java.io.InputStream;//       BLACK SPHERE
//import java.nio.ByteBuffer;
//import java.nio.ByteOrder;
//import java.nio.FloatBuffer;
//
//import javax.microedition.khronos.opengles.GL10;
//
//import android.content.Context;
//import android.graphics.Bitmap;
//import android.graphics.BitmapFactory;
//import android.graphics.Point;
//import android.opengl.GLUtils;
//
//public class MyKube {
//    private FloatBuffer mVertexBuffer;
//
//    private FloatBuffer textureBuffer;
//
//
//    int n=0;
//
//    public MyKube() {
//        float i=0;
//        int dtheta=15,dphi=15;
//
//        int theta,phi;
//        float DTOR=(float) (Math.PI/180.0f);
//
//        ByteBuffer byteBuf = ByteBuffer.allocateDirect(5000*3*4);
//        byteBuf.order(ByteOrder.nativeOrder());
//        mVertexBuffer = byteBuf.asFloatBuffer();
//        byteBuf = ByteBuffer.allocateDirect(5000*2*4);
//        byteBuf.order(ByteOrder.nativeOrder());
//        textureBuffer=byteBuf.asFloatBuffer();
//        for (theta=-90;theta<=90-dtheta;theta+=dtheta) {
//            for (phi=0;phi<=360-dphi;phi+=dphi){
//
//                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos(phi*DTOR)));
//                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin(phi*DTOR)));
//                mVertexBuffer.put((float)(Math.sin(theta*DTOR)));
//
//                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.cos(phi*DTOR)));
//                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.sin(phi*DTOR)));
//                mVertexBuffer.put((float)(Math.sin((theta+dtheta)*DTOR)));
//
//                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.cos((phi+dphi)*DTOR)));
//                mVertexBuffer.put((float)(Math.cos((theta+dtheta)*DTOR) * Math.sin((phi+dphi)*DTOR)));
//                mVertexBuffer.put((float)(Math.sin((theta+dtheta)*DTOR)));
//                n+=3;
//
//                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.cos((phi+dphi)*DTOR)));
//                mVertexBuffer.put((float)(Math.cos(theta*DTOR) * Math.sin((phi+dphi)*DTOR)));
//                mVertexBuffer.put((float)(Math.sin(theta*DTOR)));
//                n++;
//                textureBuffer.put((float)(phi/360.0f));
//                textureBuffer.put((float)((90+theta)/180.0f));
//
//                textureBuffer.put((float)(phi/360.0f));
//                textureBuffer.put((float)((90+theta+dtheta)/180.0f));
//
//                textureBuffer.put((float)((phi+dphi)/360.0f));
//                textureBuffer.put((float)((90+theta+dtheta)/180.0f));
//
//                textureBuffer.put((float)((phi+dphi)/360.0f));
//                textureBuffer.put((float)((90+theta)/180.0f));
//            }
//        }
//
//
//        mVertexBuffer.position(0);
//        textureBuffer.position(0);
//
//
//
//    }
//
//    public void draw(GL10 gl) {
//        //	gl.glFrontFace(GL10.GL_CCW);    // Front face in counter-clockwise orientation
//        //    gl.glEnable(GL10.GL_CULL_FACE); // Enable cull face
//        //  gl.glCullFace(GL10.GL_BACK);    // Cull the back face (don't display)
//        gl.glEnable(GL10.GL_BLEND);
//        gl.glBlendFunc(GL10.GL_SRC_ALPHA,GL10.GL_ONE_MINUS_SRC_ALPHA);
//        //gl.glTexEnvf(GL10.GL_TEXTURE_ENV, GL10.GL_TEXTURE_ENV_MODE, GL10.GL_BLEND);
//
//        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
//        gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);  // Enable texture-coords-array (NEW)
//        gl.glEnable(GL10.GL_TEXTURE_2D);
//        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, mVertexBuffer);
//        gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
//        //gl.glColor4f(1,0,0,0.5f);
//        int i=0;
//        for (i=0;i<n;i+=4){
//            gl.glDrawArrays(GL10.GL_TRIANGLE_FAN, i,4 );
//        }
//        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
//        gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
//        gl.glDisable(GL10.GL_TEXTURE_2D);
//        gl.glDisable(GL10.GL_BLEND);
//        //gl.glColor4f(1,1,1,1);
//    }
//
//
//}
//
