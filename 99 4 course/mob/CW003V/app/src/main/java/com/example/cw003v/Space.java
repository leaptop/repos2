package com.example.cw003v;
import android.opengl.GLES20;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
public class Space {
    private final FloatBuffer spacePosition;
    private final FloatBuffer spaceNormal;
    private final FloatBuffer spaceColor;
    Space() {
        float[] planePositionData = {
                -25.0f, -0.0f, -25.0f,
                -25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, -25.0f,
                -25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, 25.0f,
                25.0f, -0.0f, -25.0f
        };
        ByteBuffer bPos = ByteBuffer.allocateDirect(planePositionData.length
                * 4);
        bPos.order(ByteOrder.nativeOrder());
        spacePosition = bPos.asFloatBuffer();
        float[] planeNormalData = {
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 1.0f, 0.0f

        };
        ByteBuffer bNormal = ByteBuffer.allocateDirect(planeNormalData.length  * 4);
        bNormal.order(ByteOrder.nativeOrder());
        spaceNormal = bNormal.asFloatBuffer();
        float[] planeColorData = {
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f,
                0.3f, 0.3f, 0.3f, 1.0f
        };
        ByteBuffer bColor = ByteBuffer.allocateDirect(planeColorData.length *
                4);
        bColor.order(ByteOrder.nativeOrder());
        spaceColor = bColor.asFloatBuffer();
        spacePosition.put(planePositionData).position(0);
        spaceNormal.put(planeNormalData).position(0);
        spaceColor.put(planeColorData).position(0);
    }
    void render(int positionAttribute, int normalAttribute, int
            colorAttribute, boolean onlyPosition) {
        spacePosition.position(0);
        spaceNormal.position(0);
        spaceColor.position(0);
        GLES20.glVertexAttribPointer(positionAttribute, 3, GLES20.GL_FLOAT,
                false,
                0, spacePosition);
        GLES20.glEnableVertexAttribArray(positionAttribute);
        if (!onlyPosition) {
            GLES20.glVertexAttribPointer(normalAttribute, 3, GLES20.GL_FLOAT,
                    false,
                    0, spaceNormal);
            GLES20.glEnableVertexAttribArray(normalAttribute);
            GLES20.glVertexAttribPointer(colorAttribute, 4, GLES20.GL_FLOAT,
                    false,
                    0, spaceColor);
            GLES20.glEnableVertexAttribArray(colorAttribute);
        }
        GLES20.glDrawArrays(GLES20.GL_TRIANGLES, 0, 6);
    }
}
