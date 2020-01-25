// ======================================================================
//  main.cpp
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

#include <QApplication>
#include "Widget.h"

// ----------------------------------------------------------------------
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Widget       wgt1;
    Widget       wgt2;

    wgt1.setWindowTitle("Widget1");
    wgt1.setObjectName("Widget1");
    wgt1.resize(200, 200);
    wgt1.show();

    wgt2.setWindowTitle("Widget2");
    wgt2.setObjectName("Widget2");
    wgt2.resize(200, 200);
    wgt2.show();

    return app.exec();
}
