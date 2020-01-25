// ======================================================================
//  Calculator.h
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

#include <QWidget>
#include <QStack>

class QLCDNumber;
class QPushButton;

// ======================================================================
class Calculator : public QWidget {
    Q_OBJECT
private:
    QLCDNumber*     m_plcd;
    QStack<QString> m_stk;
    QString         m_strDisplay;

public:
    Calculator(QWidget* pwgt = 0);

    QPushButton* createButton(const QString& str);
    void         calculate   (                  );

public slots:
    void slotButtonClicked();
};

