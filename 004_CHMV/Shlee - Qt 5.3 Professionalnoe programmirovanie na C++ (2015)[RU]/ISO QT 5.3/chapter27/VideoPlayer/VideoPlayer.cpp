// ======================================================================
//  VideoPlayer.cpp
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
#include <QVideoWidget>

#include "VideoPlayer.h"

// ----------------------------------------------------------------------
VideoPlayer::VideoPlayer(QWidget* pwgt/*=0*/) : SoundPlayer(pwgt)
{

    QVideoWidget* pvw = new QVideoWidget;
    pvw->setMinimumSize(300, 300);

    m_pvbxMainLayout->addWidget(pvw);    

    m_pmp->setVideoOutput(pvw);
}

