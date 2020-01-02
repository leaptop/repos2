// ======================================================================
//  MyView.h
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

#include <QGraphicsView>

// ======================================================================
class MyView: public QGraphicsView {
Q_OBJECT
public:
    MyView(QGraphicsScene* pScene, QWidget* pwgt = 0) 
        : QGraphicsView(pScene, pwgt)
    {
    }

public slots:
    void slotZoomIn()
    {
        scale(1.1, 1.1);
    }

    void slotZoomOut()
    {
        scale(1 / 1.1, 1 / 1.1);
    }

    void slotRotateLeft()
    {
        rotate(-5);
    }

    void slotRotateRight()
    {
        rotate(5);
    }
};
