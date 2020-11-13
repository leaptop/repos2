package com.example.myapplication

import android.graphics.Bitmap
import java.nio.FloatBuffer

/**
 * Created by r21nomi on 2017/06/04.
 */
internal data class RenderInfo(
    val vertexBuffer: FloatBuffer,
    var texcoordBuffer: FloatBuffer?,
    var programId: Int,
    var textureId: Int,
    val bgImage: Bitmap,
    var alpha: Float
)