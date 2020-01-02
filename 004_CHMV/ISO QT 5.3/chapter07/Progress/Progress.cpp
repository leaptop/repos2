// ======================================================================
//  Progress.cpp
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
#include "Progress.h"

// ----------------------------------------------------------------------
Progress::Progress(QWidget* pwgt/*= 0*/) 
    : QWidget(pwgt)
    , m_nStep(0)
{
    m_pprb = new QProgressBar;
    m_pprb->setRange(0, 5);
    m_pprb->setMinimumWidth(200);
    m_pprb->setAlignment(Qt::AlignCenter);

    QPushButton* pcmdStep  = new QPushButton("&Step");
    QPushButton* pcmdReset = new QPushButton("&Reset");

    QObject::connect(pcmdStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(pcmdReset, SIGNAL(clicked()), SLOT(slotReset()));

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(m_pprb);
    phbxLayout->addWidget(pcmdStep);
    phbxLayout->addWidget(pcmdReset);
    setLayout(phbxLayout);
}

// ----------------------------------------------------------------------
void Progress::slotStep()
{
    m_pprb->setValue(++m_nStep);
}

// ----------------------------------------------------------------------
void Progress::slotReset()
{
    m_nStep = 0;
    m_pprb->reset();    
}
