// ======================================================================
//  KeyFilter.h
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
class KeyFilter : public QObject {
protected:
    bool eventFilter(QObject* pobj, QEvent* pe)
    {
        if (pe->type() == QEvent::KeyPress) {
            if (((QKeyEvent*)pe)->key() == Qt::Key_Z) {
                QKeyEvent keyEvent(QEvent::KeyPress, 
                                   Qt::Key_A, 
                                   Qt::NoModifier, 
                                   "A"
                                  );
                QApplication::sendEvent(pobj, &keyEvent);            
                return true;
            }
        }
        return false;
    }

public:
    KeyFilter(QObject* pobj = 0)
        : QObject(pobj)
    {
    }
};

