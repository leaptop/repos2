// ======================================================================
//  Widget.h
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

#include <QPoint>
#include <QLabel>

// ======================================================================
class Widget : public QLabel {
Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag();

protected:
    virtual void mousePressEvent(QMouseEvent*    );
    virtual void mouseMoveEvent (QMouseEvent*    );
    virtual void dragEnterEvent (QDragEnterEvent*);
    virtual void dropEvent      (QDropEvent*     );

public:
    Widget(QWidget* pwgt = 0);
};

