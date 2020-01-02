// ======================================================================
//  TurtleWorkArea.h
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
#include <QScriptEngine>

class QTextEdit;
class Turtle;

// ======================================================================
class TurtleWorkArea : public QWidget {
Q_OBJECT
private:
    QTextEdit*    m_ptxt;
    QScriptEngine m_scriptEngine;
    Turtle*       m_pTurtle;

public:
    TurtleWorkArea(QWidget* pwgt = 0);

private slots:
    void slotEvaluate (   );
    void slotApplyCode(int);
};

