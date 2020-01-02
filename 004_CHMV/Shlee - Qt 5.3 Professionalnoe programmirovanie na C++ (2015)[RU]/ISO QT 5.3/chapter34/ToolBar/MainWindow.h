// ======================================================================
//  MainWindow.h
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

#pragma once

#include <QtWidgets>

// ======================================================================
class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget* pwgt = 0) : QMainWindow(pwgt) 
    {
        addToolBar(Qt::TopToolBarArea, createToolBar());
        addToolBar(Qt::BottomToolBarArea, createToolBar());
        addToolBar(Qt::LeftToolBarArea, createToolBar());
        addToolBar(Qt::RightToolBarArea, createToolBar());
    }

    QToolBar* createToolBar()
    {
        QToolBar* ptb = new QToolBar("Linker ToolBar");

        ptb->addAction(QPixmap(":/img1.png"), "1", this, SLOT(slotNoImpl()));
        ptb->addAction(QPixmap(":/img2.png"), "2", this, SLOT(slotNoImpl()));
        ptb->addSeparator();
        ptb->addAction(QPixmap(":/img3.png"), "3", this, SLOT(slotNoImpl()));
        ptb->addAction(QPixmap(":/img4.png"), "4", this, SLOT(slotNoImpl()));

        return ptb;
    }

public slots:
    void slotNoImpl()
    {
        QMessageBox::information(0, "Message", "Not implemented");
    }
};
