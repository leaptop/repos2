// ======================================================================
//  GrabWidget.cpp
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
#include "GrabWidget.h"

// ----------------------------------------------------------------------
GrabWidget::GrabWidget(QWidget* pwgt /*=0*/) : QWidget(pwgt)
{
    resize(640, 480);

    m_plbl = new QLabel();

    QPushButton* pcmd = new QPushButton("Capture Screen");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotGrabScreen()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(pcmd);
    pvbxLayout->addWidget(m_plbl);
    setLayout(pvbxLayout);
}

// ----------------------------------------------------------------------
void GrabWidget::slotGrabScreen()
{
    QDesktopWidget* pwgt = QApplication::desktop();
    QPixmap         pic  = QPixmap::grabWindow(pwgt->screen()->winId());

    m_plbl->setPixmap(pic.scaled(m_plbl->size()));
}
