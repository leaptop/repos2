package com.example.cw002;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import android.opengl.GLES20;

public class Plane {
    private final FloatBuffer planePosition;
    private final FloatBuffer planeNormal;
    private final FloatBuffer planeColor;

    Plane() {
        float[] planePositionData = {
                -25.0f, -0.0f, -25.0f,
                -25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, -25.0f,
                -25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, -25.0f
        };
        ByteBuffer bPos = ByteBuffer.allocateDirect(planePositionData.length * 4);
        bPos.order(ByteOrder.nativeOrder());
        planePosition = bPos.asFloatBuffer();

        float[] planeNormalData = {
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f
        };
        ByteBuffer bNormal = ByteBuffer.allocateDirect(planeNormalData.length * 4);
        bNormal.order(ByteOrder.nativeOrder());
        planeNormal = bNormal.asFloatBuffer();

        float[] planeColorData = {
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f
        };
        ByteBuffer bColor = ByteBuffer.allocateDirect(planeColorData.length * 4);
        bColor.order(ByteOrder.nativeOrder());
        planeColor = bColor.asFloatBuffer();

        planePosition.put(planePositionData).position(0);
        planeNormal.put(planeNormalData).position(0);
        planeColor.put(planeColorData).position(0);
    }

    void render(int positionAttribute, int normalAttribute, int colorAttribute, boolean onlyPosition) {
        planePosition.position(0);
        planeNormal.position(0);
        planeColor.position(0);

        GLES20.glVertexAttribPointer(positionAttribute, 3, GLES20.GL_FLOAT, false,
                0, planePosition);
        GLES20.glEnableVertexAttribArray(positionAttribute);

        if (!onlyPosition) {
            GLES20.glVertexAttribPointer(normalAttribute, 3, GLES20.GL_FLOAT, false,
                    0, planeNormal);
            GLES20.glEnableVertexAttribArray(normalAttribute);
            GLES20.glVertexAttribPointer(colorAttribute, 4, GLES20.GL_FLOAT, false,
                    0, planeColor);
            GLES20.glEnableVertexAttribArray(colorAttribute);
        }

        GLES20.glDrawArrays(GLES20.GL_TRIANGLES, 0, 6);
    }
}