// ======================================================================
//  Calculation.h
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

#include <QObject>

// ======================================================================
class Calculation : public QObject {
Q_OBJECT
private:
    Q_PROPERTY(qulonglong input WRITE  setInputValue
                                READ   inputValue
                                NOTIFY inputValueChanged
              )
    Q_PROPERTY(qulonglong result READ   resultValue
                                 NOTIFY resultValueChanged
              )

    qulonglong input;
    qulonglong result;

public:
    Calculation(QObject* pobj = 0);

    Q_INVOKABLE qulonglong factorial(const qulonglong& n);

    qulonglong inputValue   (                 ) const;
    void       setInputValue(const qulonglong&);
    qulonglong resultValue  (                 ) const;

signals:
    void inputValueChanged (qulonglong);
    void resultValueChanged(qulonglong);
};

