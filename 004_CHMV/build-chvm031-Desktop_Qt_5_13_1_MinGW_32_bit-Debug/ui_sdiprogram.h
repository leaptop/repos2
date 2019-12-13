/********************************************************************************
** Form generated from reading UI file 'sdiprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAM_H
#define UI_SDIPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgram
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SDIProgram)
    {
        if (SDIProgram->objectName().isEmpty())
            SDIProgram->setObjectName(QString::fromUtf8("SDIProgram"));
        SDIProgram->resize(800, 600);
        centralwidget = new QWidget(SDIProgram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SDIProgram->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SDIProgram);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        SDIProgram->setMenuBar(menubar);
        statusbar = new QStatusBar(SDIProgram);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SDIProgram->setStatusBar(statusbar);

        retranslateUi(SDIProgram);

        QMetaObject::connectSlotsByName(SDIProgram);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgram)
    {
        SDIProgram->setWindowTitle(QCoreApplication::translate("SDIProgram", "SDIProgram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDIProgram: public Ui_SDIProgram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAM_H
