#include "opengl.h"
#include <GLES2/gl2.h>
#include <GLES/gl.h>

void onSurfaceCreated() {
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}

void onSurfaceChanged() {
    // No-op
}

void onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
}