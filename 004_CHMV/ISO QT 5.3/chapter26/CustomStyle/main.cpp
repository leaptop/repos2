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

#include <QtWidgets>
#include "CustomStyle.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QPushButton* pcmdA = new QPushButton ("Button1");
    QPushButton* pcmdB = new QPushButton ("Button2");
    QPushButton* pcmdC = new QPushButton ("Button3");

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addWidget(pcmdC);
    wgt.setLayout(pvbxLayout);

    app.setStyle(new CustomStyle);
    wgt.show();

    return app.exec();
}
