// ======================================================================
//  OGLQuad.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include "OGLQuad.h"

// ----------------------------------------------------------------------
OGLQuad::OGLQuad(QWidget* pwgt/*= 0*/) : QGLWidget(pwgt) 
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::initializeGL()
{
    qglClearColor(Qt::black);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(0, 100, 100, 0, -1, 1); 
}

// ----------------------------------------------------------------------
/*virtual*/void OGLQuad::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); 
        glVertex2f(0, 100);

        glColor3f(0, 1, 0);
        glVertex2f(100, 100);

        glColor3f(0, 0, 1);
        glVertex2f(100, 0);

        glColor3f(1, 1, 1);
        glVertex2f(0, 0);
    glEnd();
}
