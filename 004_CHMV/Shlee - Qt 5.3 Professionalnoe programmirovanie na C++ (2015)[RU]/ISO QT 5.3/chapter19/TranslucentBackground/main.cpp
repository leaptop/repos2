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
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLabel       lbl;
  
    lbl.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    lbl.setAttribute(Qt::WA_TranslucentBackground);
    lbl.setPixmap(QPixmap(":/happyos.png"));

    QPushButton* pcmdQuit = new QPushButton("X");
    pcmdQuit->setFixedSize(16, 16);
    QObject::connect(pcmdQuit, SIGNAL(clicked()), &app, SLOT(quit()));

    //setup layout
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pcmdQuit);
    pvbx->addStretch(1);
    lbl.setLayout(pvbx);

    lbl.show();    

    return app.exec();
}
