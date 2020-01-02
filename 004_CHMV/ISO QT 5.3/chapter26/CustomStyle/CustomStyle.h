// ======================================================================
//  CustomStyle.h
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

class QPainter;

// ======================================================================
class CustomStyle : public QCommonStyle {
public:
    virtual void polish  (QWidget* pwgt);
    virtual void unpolish(QWidget* pwgt);

    virtual void drawPrimitive(      PrimitiveElement elem, 
                               const QStyleOption*    popt,
                                     QPainter*        ppainter, 
                               const QWidget*         pwgt = 0
                              ) const;
};
