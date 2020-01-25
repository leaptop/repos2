/********************************************************************************
** Form generated from reading UI file 'alexeevdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALEXEEVDIALOG_H
#define UI_ALEXEEVDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AlexeevDialog
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QFrame *frame;

    void setupUi(QDialog *AlexeevDialog)
    {
        if (AlexeevDialog->objectName().isEmpty())
            AlexeevDialog->setObjectName(QString::fromUtf8("AlexeevDialog"));
        AlexeevDialog->resize(498, 389);
        lineEdit = new QLineEdit(AlexeevDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(280, 20, 201, 20));
        lineEdit_2 = new QLineEdit(AlexeevDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(340, 70, 113, 20));
        label_2 = new QLabel(AlexeevDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 70, 61, 16));
        label_3 = new QLabel(AlexeevDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 110, 101, 16));
        pushButton = new QPushButton(AlexeevDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 220, 75, 23));
        pushButton_2 = new QPushButton(AlexeevDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 350, 75, 23));
        radioButton = new QRadioButton(AlexeevDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(330, 170, 82, 17));
        radioButton_2 = new QRadioButton(AlexeevDialog);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(390, 170, 82, 17));
        dateEdit = new QDateEdit(AlexeevDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(350, 110, 110, 22));
        label_4 = new QLabel(AlexeevDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 20, 47, 13));
        label = new QLabel(AlexeevDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 210, 91, 16));
        lineEdit_3 = new QLineEdit(AlexeevDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(310, 210, 113, 20));
        frame = new QFrame(AlexeevDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 20, 171, 181));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(AlexeevDialog);

        QMetaObject::connectSlotsByName(AlexeevDialog);
    } // setupUi

    void retranslateUi(QDialog *AlexeevDialog)
    {
        AlexeevDialog->setWindowTitle(QCoreApplication::translate("AlexeevDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("AlexeevDialog", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("AlexeevDialog", "\320\224\320\260\321\202\320\260 \320\240\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("AlexeevDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AlexeevDialog", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
        radioButton->setText(QCoreApplication::translate("AlexeevDialog", "\320\234", nullptr));
        radioButton_2->setText(QCoreApplication::translate("AlexeevDialog", "\320\226", nullptr));
        label_4->setText(QCoreApplication::translate("AlexeevDialog", "\320\244\320\230\320\236", nullptr));
        label->setText(QCoreApplication::translate("AlexeevDialog", "\320\273\321\216\320\261\320\270\320\274\321\213\320\271 \321\206\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlexeevDialog: public Ui_AlexeevDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALEXEEVDIALOG_H
