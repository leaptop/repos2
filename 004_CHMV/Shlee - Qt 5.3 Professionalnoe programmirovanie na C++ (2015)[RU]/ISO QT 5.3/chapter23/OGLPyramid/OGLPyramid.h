// ======================================================================
//  OGLPyramid.h
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

#pragma once

#include <QGLWidget>

// ======================================================================
class OGLPyramid : public QGLWidget {
private:
    GLuint  m_nPyramid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint  m_ptPosition;

protected:
    virtual void   initializeGL   (                       );
    virtual void   resizeGL       (int nWidth, int nHeight);
    virtual void   paintGL        (                       );
    virtual void   mousePressEvent(QMouseEvent* pe        );
    virtual void   mouseMoveEvent (QMouseEvent* pe        );
            GLuint createPyramid  (GLfloat fSize = 1.0f   );

public:
    OGLPyramid(QWidget* pwgt = 0);
};

