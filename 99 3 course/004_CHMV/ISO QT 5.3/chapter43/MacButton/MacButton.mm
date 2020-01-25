// ======================================================================
//  MacButton.mm
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

#import "MacButton.h"
#import <Cocoa/Cocoa.h>
#include <QtWidgets>

// ----------------------------------------------------------------------
ButtonContainer::ButtonContainer(QWidget* pwgt/*=0*/)
    : QMacCocoaViewContainer(0, pwgt)
{
    NSAutoreleasePool* ppool = [[NSAutoreleasePool alloc] init];

    NSButton* pcmd = [[NSButton alloc] init];

    [pcmd setButtonType:NSSwitchButton];
    [pcmd setTitle:@"Mac Check Button"];
    [pcmd setState:YES];

    setCocoaView(pcmd);

    [pcmd release];
    [ppool release];
}

// ----------------------------------------------------------------------
QSize ButtonContainer::sizeHint() const
{
    return QSize(150, 40);
}

// ----------------------------------------------------------------------
MacButton::MacButton(QWidget* pwgt) : QWidget(pwgt/*=0*/)
{
    ButtonContainer* pcmd = new ButtonContainer(this);

    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->setMargin(0);
    pvbx->addWidget(pcmd);
    setLayout(pvbx);
}

