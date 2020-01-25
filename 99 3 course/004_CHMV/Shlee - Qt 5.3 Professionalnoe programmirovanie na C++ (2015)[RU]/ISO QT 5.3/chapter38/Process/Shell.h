// ======================================================================
//  Shell.h --
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
class Shell : public QWidget {
Q_OBJECT
private:
    QProcess*  m_process;
    QLineEdit* m_ptxtCommand;
    QTextEdit* m_ptxtDisplay;

public:
    // ------------------------------------------------------------------
    Shell(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        m_process     = new QProcess(this);
        m_ptxtDisplay = new QTextEdit;

        QLabel* plbl = new QLabel("&Command:");

        m_ptxtCommand = new QLineEdit("dir");
        plbl->setBuddy(m_ptxtCommand);

        QPushButton* pcmd = new QPushButton("&Enter");

        connect(m_process, 
                SIGNAL(readyReadStandardOutput()), 
                SLOT(slotDataOnStdout())
               );
        connect(m_ptxtCommand, 
                SIGNAL(returnPressed()), 
                SLOT(slotReturnPressed())
               );
        connect(pcmd, SIGNAL(clicked()), SLOT(slotReturnPressed()));

        //Layout setup
        QHBoxLayout* phbxLayout = new QHBoxLayout;    
        phbxLayout->addWidget(plbl);
        phbxLayout->addWidget(m_ptxtCommand);
        phbxLayout->addWidget(pcmd);

        QVBoxLayout* pvbxLayout = new QVBoxLayout;    
        pvbxLayout->addWidget(m_ptxtDisplay);
        pvbxLayout->addLayout(phbxLayout);
        setLayout(pvbxLayout);
    }

public slots:
    // ------------------------------------------------------------------
    void slotDataOnStdout()
    {
        m_ptxtDisplay->append(m_process->readAllStandardOutput());
    }

    // ------------------------------------------------------------------
    void slotReturnPressed()
    {
        QString strCommand = "";
#ifdef Q_WS_WIN
        strCommand = "cmd /C ";
#endif
        strCommand += m_ptxtCommand->text();
        m_process->start(strCommand);
    }
};  


