package com.example.fogeffect;

import android.app.Activity;
import android.os.Bundle;

/**
 * The initial Android Activity, setting and initiating
 * the OpenGL ES Renderer Class @see Lesson16.java
 *
 * @author Savas Ziplies (nea/INsanityDesign)
 */
public class Run extends Activity {

    /** Our own OpenGL View overridden */
    private Fog fog;

    /**
     * Initiate our @see Lesson16.java,
     * which is GLSurfaceView and Renderer
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //Initiate our Lesson with this Activity Context handed over
        fog = new Fog(this);
        //Set the lesson as View to the Activity
        setContentView(fog);
    }

    /**
     * Remember to resume our Lesson
     */
    @Override
    protected void onResume() {
        super.onResume();
        fog.onResume();
    }

    /**
     * Also pause our Lesson
     */
    @Override
    protected void onPause() {
        super.onPause();
        fog.onPause();
    }

}