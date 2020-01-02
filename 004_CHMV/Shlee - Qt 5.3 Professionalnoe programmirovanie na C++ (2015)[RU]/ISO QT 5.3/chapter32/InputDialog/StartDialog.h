// ======================================================================
//  StartDialog.h
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
#include "InputDialog.h"

// ======================================================================
class StartDialog : public QPushButton {
Q_OBJECT
public:
    StartDialog(QWidget* pwgt = 0) : QPushButton("Press Me", pwgt) 
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }

public slots:
    void slotButtonClicked()
    {
        InputDialog* pInputDialog = new InputDialog;    
        if (pInputDialog->exec() == QDialog::Accepted) {
            QMessageBox::information(0, 
                                     "Information", 
                                     "First Name: " 
                                     + pInputDialog->firstName()
                                     + "\nLast Name: " 
                                     + pInputDialog->lastName()
                                    );
        }
        delete pInputDialog;
    } 
};
