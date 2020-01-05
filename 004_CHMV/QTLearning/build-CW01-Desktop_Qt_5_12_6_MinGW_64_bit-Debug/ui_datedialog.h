/********************************************************************************
** Form generated from reading UI file 'datedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEDIALOG_H
#define UI_DATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCalendarWidget *calendarWidget;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *DateDialog)
    {
        if (DateDialog->objectName().isEmpty())
            DateDialog->setObjectName(QString::fromUtf8("DateDialog"));
        DateDialog->resize(892, 725);
        buttonBox = new QDialogButtonBox(DateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 380, 121, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        calendarWidget = new QCalendarWidget(DateDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 50, 351, 291));
        plainTextEdit = new QPlainTextEdit(DateDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(400, 50, 471, 661));

        retranslateUi(DateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DateDialog);
    } // setupUi

    void retranslateUi(QDialog *DateDialog)
    {
        DateDialog->setWindowTitle(QApplication::translate("DateDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateDialog: public Ui_DateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEDIALOG_H
