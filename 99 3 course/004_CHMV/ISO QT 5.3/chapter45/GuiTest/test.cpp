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
#include <QtWidgets>

// ======================================================================
class Test_QLineEdit : public QObject {
Q_OBJECT
private slots:
    void edit();
};

// ----------------------------------------------------------------------
void Test_QLineEdit::edit()
{
    QLineEdit txt;
    QTest::keyClicks(&txt, "ABCDEFGH");

    QCOMPARE(txt.text(), QString("ABCDEFGH"));
    QVERIFY(txt.isModified());
}

QTEST_MAIN(Test_QLineEdit)
#include "test.moc"
