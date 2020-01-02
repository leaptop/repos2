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

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget       wgt;
    QDial*        pdia = new QDial;
    QProgressBar* pprb = new QProgressBar;

    pdia->setRange(0, 100);
    pdia->setNotchTarget(5);
    pdia->setNotchesVisible(true);
    QObject::connect(pdia, SIGNAL(valueChanged(int)), 
                     pprb, SLOT(setValue(int))
                    );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pdia);
    pvbxLayout->addWidget(pprb);
    wgt.setLayout(pvbxLayout);

    wgt.resize(180, 200);
    wgt.show();

    return app.exec();
}
