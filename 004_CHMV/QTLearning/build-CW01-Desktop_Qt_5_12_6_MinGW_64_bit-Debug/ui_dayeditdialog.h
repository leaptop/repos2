/********************************************************************************
** Form generated from reading UI file 'dayeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYEDITDIALOG_H
#define UI_DAYEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_dayEditDialog
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *dayEditDialog)
    {
        if (dayEditDialog->objectName().isEmpty())
            dayEditDialog->setObjectName(QString::fromUtf8("dayEditDialog"));
        dayEditDialog->resize(706, 528);
        textEdit = new QTextEdit(dayEditDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 621, 421));
        pushButton = new QPushButton(dayEditDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 500, 211, 21));
        textEdit_2 = new QTextEdit(dayEditDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 20, 621, 31));

        retranslateUi(dayEditDialog);

        QMetaObject::connectSlotsByName(dayEditDialog);
    } // setupUi

    void retranslateUi(QDialog *dayEditDialog)
    {
        dayEditDialog->setWindowTitle(QApplication::translate("dayEditDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("dayEditDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dayEditDialog: public Ui_dayEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYEDITDIALOG_H
