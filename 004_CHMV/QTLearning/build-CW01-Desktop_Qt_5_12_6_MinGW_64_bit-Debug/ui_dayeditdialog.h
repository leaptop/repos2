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
    QPushButton *pushButton_2;

    void setupUi(QDialog *dayEditDialog)
    {
        if (dayEditDialog->objectName().isEmpty())
            dayEditDialog->setObjectName(QString::fromUtf8("dayEditDialog"));
        dayEditDialog->resize(949, 553);
        textEdit = new QTextEdit(dayEditDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 60, 901, 471));
        pushButton = new QPushButton(dayEditDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 121, 21));
        pushButton_2 = new QPushButton(dayEditDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 20, 131, 21));

        retranslateUi(dayEditDialog);

        QMetaObject::connectSlotsByName(dayEditDialog);
    } // setupUi

    void retranslateUi(QDialog *dayEditDialog)
    {
        dayEditDialog->setWindowTitle(QApplication::translate("dayEditDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("dayEditDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("dayEditDialog", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dayEditDialog: public Ui_dayEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYEDITDIALOG_H
