/********************************************************************************
** Form generated from reading UI file 'calendardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARDIALOG_H
#define UI_CALENDARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarDialog
{
public:
    QWidget *centralwidget;
    QToolButton *yearBackButton;
    QToolButton *yearFrontButton;
    QToolButton *MonthBackButton;
    QToolButton *MonthFrontButton;
    QLabel *Titlelabel;
    QLabel *DateLabel;
    QPushButton *OkButton;
    QCalendarWidget *calendarWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalendarDialog)
    {
        if (CalendarDialog->objectName().isEmpty())
            CalendarDialog->setObjectName(QStringLiteral("CalendarDialog"));
        CalendarDialog->resize(800, 600);
        centralwidget = new QWidget(CalendarDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        yearBackButton = new QToolButton(centralwidget);
        yearBackButton->setObjectName(QStringLiteral("yearBackButton"));
        yearBackButton->setGeometry(QRect(110, 360, 26, 20));
        yearFrontButton = new QToolButton(centralwidget);
        yearFrontButton->setObjectName(QStringLiteral("yearFrontButton"));
        yearFrontButton->setGeometry(QRect(180, 360, 26, 20));
        MonthBackButton = new QToolButton(centralwidget);
        MonthBackButton->setObjectName(QStringLiteral("MonthBackButton"));
        MonthBackButton->setGeometry(QRect(270, 380, 26, 20));
        MonthFrontButton = new QToolButton(centralwidget);
        MonthFrontButton->setObjectName(QStringLiteral("MonthFrontButton"));
        MonthFrontButton->setGeometry(QRect(340, 370, 26, 20));
        Titlelabel = new QLabel(centralwidget);
        Titlelabel->setObjectName(QStringLiteral("Titlelabel"));
        Titlelabel->setGeometry(QRect(120, 310, 71, 16));
        DateLabel = new QLabel(centralwidget);
        DateLabel->setObjectName(QStringLiteral("DateLabel"));
        DateLabel->setGeometry(QRect(230, 310, 131, 16));
        OkButton = new QPushButton(centralwidget);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setGeometry(QRect(610, 360, 80, 21));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(450, 40, 280, 156));
        CalendarDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalendarDialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        CalendarDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(CalendarDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CalendarDialog->setStatusBar(statusbar);

        retranslateUi(CalendarDialog);

        QMetaObject::connectSlotsByName(CalendarDialog);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarDialog)
    {
        CalendarDialog->setWindowTitle(QApplication::translate("CalendarDialog", "CalendarDialog", nullptr));
        yearBackButton->setText(QApplication::translate("CalendarDialog", "...", nullptr));
        yearFrontButton->setText(QApplication::translate("CalendarDialog", "...", nullptr));
        MonthBackButton->setText(QApplication::translate("CalendarDialog", "...", nullptr));
        MonthFrontButton->setText(QApplication::translate("CalendarDialog", "...", nullptr));
        Titlelabel->setText(QApplication::translate("CalendarDialog", "Titlelabel", nullptr));
        DateLabel->setText(QApplication::translate("CalendarDialog", "DateLabel", nullptr));
        OkButton->setText(QApplication::translate("CalendarDialog", "OkButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarDialog: public Ui_CalendarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARDIALOG_H
