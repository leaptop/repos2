package com.example.cube3d;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

public class Cube {
	    private FloatBuffer mVertexBuffer;
	    private FloatBuffer mColorBuffer;
	    private ByteBuffer  mIndexBuffer;

	    //расположение вершин
	    private float vertices[] = {
                -1.0f, -0.5f, -1.0f,
                1.0f, -0.5f, -1.0f,
                1.0f,  0.5f, -1.0f,
                -1.0f, 0.5f, -1.0f,
                -1.0f, -0.5f,  1.0f,
                1.0f, -0.5f,  1.0f,
                1.0f,  0.5f,  1.0f,
                -1.0f,  0.5f,  1.0f
                };
	    //цветовая схема, в rgba
private float colors[] = {
               1.0f,  0.0f,  0.0f,  0.0f, //red
			   0.0f,  1.0f,  0.0f,  0.0f, //blue
               1.0f,  0.0f,  0.0f,  0.0f, //red
               0.0f,  1.0f,  0.0f,  0.0f, //blue
               0.0f,  0.0f,  1.0f,  0.0f, //green
               0.0f,  0.0f,  0.0f,  1.0f, //black
               0.0f,  0.0f,  1.0f,  0.0f, //green
               0.0f,  0.0f,  0.0f,  1.0f, //black

            };
		//индексация вершин
private byte indices[] = {
        0, 4, 5, 0, 5, 1, // top
        1, 5, 6, 1, 6, 2, // right
        2, 6, 7, 2, 7, 3, // bottom
        3, 7, 4, 3, 4, 0, // left
        4, 7, 6, 4, 6, 5, // face
        3, 0, 1, 3, 1, 2  // back
        };
	   
	   
	                
	    public Cube() {
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

			gl.glVertexPointer(3, GL10.GL_FLOAT, 0, mVertexBuffer);
			gl.glColorPointer(4, GL10.GL_FLOAT, 0, mColorBuffer);

			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glEnableClientState(GL10.GL_COLOR_ARRAY);

			gl.glDrawElements(GL10.GL_TRIANGLES, 36, GL10.GL_UNSIGNED_BYTE,
					mIndexBuffer);


			gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glDisableClientState(GL10.GL_COLOR_ARRAY);
		}
}
