// ======================================================================
//  SystemTray.cpp
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
#include "SystemTray.h"

// ----------------------------------------------------------------------
SystemTray::SystemTray(QWidget* pwgt /*=0*/) 
    : QLabel("<H1>Application Window</H1>", pwgt)
    , m_bIconSwitcher(false)
{
    setWindowTitle("System Tray");

    QAction* pactShowHide = 
        new QAction("&Show/Hide Application Window", this);

    connect(pactShowHide, SIGNAL(triggered()), 
            this,         SLOT(slotShowHide())
           );

    QAction* pactShowMessage = new QAction("S&how Message", this);
    connect(pactShowMessage, SIGNAL(triggered()), 
            this,            SLOT(slotShowMessage())
           );

    QAction* pactChangeIcon = new QAction("&Change Icon", this);
    connect(pactChangeIcon, SIGNAL(triggered()), 
            this,           SLOT(slotChangeIcon())
           );

    QAction* pactQuit = new QAction("&Quit", this);
    connect(pactQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_ptrayIconMenu = new QMenu(this);
    m_ptrayIconMenu->addAction(pactShowHide);
    m_ptrayIconMenu->addAction(pactShowMessage);
    m_ptrayIconMenu->addAction(pactChangeIcon);
    m_ptrayIconMenu->addAction(pactQuit);

    m_ptrayIcon = new QSystemTrayIcon(this);
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    m_ptrayIcon->setToolTip("System Tray");

    slotChangeIcon();

    m_ptrayIcon->show();
}

// ----------------------------------------------------------------------
/*virtual*/void SystemTray::closeEvent(QCloseEvent*)
{
    if (m_ptrayIcon->isVisible()) {
        hide();
    }
}

// ----------------------------------------------------------------------
void SystemTray::slotShowHide()
{
    setVisible(!isVisible());
}

// ----------------------------------------------------------------------
void SystemTray::slotShowMessage()
{
    m_ptrayIcon->showMessage("For your information",
                             "You have selected the "
                             "\"Show Message!\" option",
                             QSystemTrayIcon::Information,
                             3000
                            );
}

// ----------------------------------------------------------------------
void SystemTray::slotChangeIcon()
{
    m_bIconSwitcher = !m_bIconSwitcher;
    QString strPixmapName = m_bIconSwitcher ? ":/images/img1.bmp" 
                                            : ":/images/img2.bmp";
    m_ptrayIcon->setIcon(QPixmap(strPixmapName));

}
