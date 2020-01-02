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

    QWidget      wgt;
    QPushButton* pcmdNormal = new QPushButton("&Normal Button");

    QPushButton* pcmdToggle = new QPushButton("&Toggle Button");
    pcmdToggle->setCheckable(true);
    pcmdToggle->setChecked(true);

    QPushButton* pcmdFlat = new QPushButton("&Flat Button");
    pcmdFlat->setFlat(true);

    QPixmap pix(":/ChordsMaestro.png");
    QPushButton* pcmdPix = new QPushButton ("&Pixmap Button");
    pcmdPix->setIcon(pix);
    pcmdPix->setIconSize(pix.size());

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdNormal);    
    pvbxLayout->addWidget(pcmdToggle);
    pvbxLayout->addWidget(pcmdFlat); 
    pvbxLayout->addWidget(pcmdPix); 
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
