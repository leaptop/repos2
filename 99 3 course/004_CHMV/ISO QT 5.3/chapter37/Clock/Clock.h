// ======================================================================
//  Clock.h
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
class Clock : public QLabel {
    Q_OBJECT

public:
    Clock(QWidget* pwgt = 0) : QLabel(pwgt)
    {
        QTimer* ptimer = new QTimer(this);
        connect(ptimer, SIGNAL(timeout()), SLOT(slotUpdateDateTime()));
        ptimer->start(500);
        slotUpdateDateTime();
    }

public slots:
    void slotUpdateDateTime()
    {
        QString str = 
            QDateTime::currentDateTime().toString(Qt::SystemLocaleDate);
        setText("<H2><CENTER>" + str + "</CENTER></H2>");
    }
};
