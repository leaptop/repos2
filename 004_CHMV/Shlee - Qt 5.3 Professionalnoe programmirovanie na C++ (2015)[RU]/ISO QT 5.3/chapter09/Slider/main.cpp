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

    QWidget  wgt;
    QSlider* psld = new QSlider(Qt::Horizontal);
    QLabel*  plbl = new QLabel("3");

    psld->setRange(0, 9);
    psld->setPageStep(2);
    psld->setValue(3);
    psld->setTickInterval(2);
    psld->setTickPosition(QSlider::TicksBelow);
    QObject::connect(psld, SIGNAL(valueChanged(int)), 
                     plbl, SLOT(setNum(int))
                    );

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(psld);    
    phbxLayout->addWidget(plbl); 
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}
