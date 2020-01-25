/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_birthday;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QLabel *label_phone;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_dolzhnost;
    QLineEdit *lineEdit_fio;
    QLabel *label_dolzhnost;
    QLabel *label_fio;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 468);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(64, 21, 450, 259));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_3->addLayout(verticalLayout, 0, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_birthday = new QLabel(layoutWidget);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));
        label_birthday->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_birthday, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 2);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(dateEdit, 0, 1, 1, 1);

        label_phone = new QLabel(layoutWidget);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout_2->addWidget(label_phone, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        lineEdit_dolzhnost = new QLineEdit(layoutWidget);
        lineEdit_dolzhnost->setObjectName(QString::fromUtf8("lineEdit_dolzhnost"));

        gridLayout->addWidget(lineEdit_dolzhnost, 1, 1, 1, 1);

        lineEdit_fio = new QLineEdit(layoutWidget);
        lineEdit_fio->setObjectName(QString::fromUtf8("lineEdit_fio"));

        gridLayout->addWidget(lineEdit_fio, 0, 1, 1, 1);

        label_dolzhnost = new QLabel(layoutWidget);
        label_dolzhnost->setObjectName(QString::fromUtf8("label_dolzhnost"));
        label_dolzhnost->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_dolzhnost, 1, 0, 1, 1);

        label_fio = new QLabel(layoutWidget);
        label_fio->setObjectName(QString::fromUtf8("label_fio"));
        label_fio->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_fio, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 400, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("background:rgb(176, 255, 185)"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_birthday->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_phone->setText(QString());
        lineEdit_fio->setText(QString());
        label_dolzhnost->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_fio->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
