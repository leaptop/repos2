// ======================================================================
//  test.cpp
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

#include <QtTest>
#include "MyClass.h"

// ======================================================================
class Test_MyClass : public QObject {
Q_OBJECT
private slots:
    void min();
    void max();
};

// ----------------------------------------------------------------------
void Test_MyClass::min()
{
    MyClass myClass;
    QCOMPARE(myClass.min(25, 0), 0);
    QCOMPARE(myClass.min(-12, -5), -12);
    QCOMPARE(myClass.min(2007, 2007), 2007);
    QCOMPARE(myClass.min(-12, 5), -12);
}

// ----------------------------------------------------------------------
void Test_MyClass::max()
{
    MyClass myClass;
    QCOMPARE(myClass.max(25, 0), 25);
    QCOMPARE(myClass.max(-12, -5), -5);
    QCOMPARE(myClass.max(2007, 2007), 2007);
    QCOMPARE(myClass.max(-12, 5), 5);
}

QTEST_MAIN(Test_MyClass)
#include "test.moc"
