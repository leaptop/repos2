// ======================================================================
//  MainWindow.h
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

#include <QtWidgets>

// ======================================================================
class MainWindow : public QMainWindow {
Q_OBJECT
private:
    QLabel* m_plblX;
    QLabel* m_plblY;

protected:
    virtual void mouseMoveEvent(QMouseEvent* pe)
    {
        m_plblX->setText("X=" + QString().setNum(pe->x()));
        m_plblY->setText("Y=" + QString().setNum(pe->y()));
    }

public:
    MainWindow(QWidget* pwgt = 0) : QMainWindow(pwgt) 
    {
       setMouseTracking(true);

       m_plblX = new QLabel(this);
       m_plblY = new QLabel(this);
       statusBar()->addWidget(m_plblY);
       statusBar()->addWidget(m_plblX);       
    }
};
