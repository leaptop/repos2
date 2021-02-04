package com.example.lab7;

public class JNIWrapper {

    static {
        System.loadLibrary("native-lib");
    }

    public static native void onSurfaceCreated();

    public static native void onSurfaceChanged(int width, int height);

    public static native void onDrawFrame();
}