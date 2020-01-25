// ======================================================================
//  MyThread.cpp
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
class MyWorker : public QObject {
Q_OBJECT
private:
    int    m_nValue;
    QTimer m_timer;

public:
    MyWorker(QObject* pobj = 0) : QObject(pobj)
                                , m_nValue(10)
    {
        connect(&m_timer, SIGNAL(timeout()), SLOT(setNextValue()));
    }

    void doWork()
    {
        m_timer.start(1000);
    }

signals:
    void valueChanged(int);
    void finished    (   );

public slots:
    void setNextValue()
    {
        emit valueChanged(--m_nValue);

        if(!m_nValue){
            emit finished();
        }
    }
};

// ======================================================================
class MyThread : public QThread {
Q_OBJECT
public:
    MyThread()
    {
    }

    void run()
    {
        exec();
    }
};
