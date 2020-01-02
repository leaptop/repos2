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
#include "CustomWidget.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    CustomWidget* pcw  = new CustomWidget;
    QScrollBar*   phsb = new QScrollBar(Qt::Horizontal);

    phsb->setRange(0, 100); 

    QObject::connect(phsb, SIGNAL(valueChanged(int)), 
                     pcw, SLOT(slotSetProgress(int))
                    );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(pcw);
    pvbxLayout->addWidget(phsb);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
