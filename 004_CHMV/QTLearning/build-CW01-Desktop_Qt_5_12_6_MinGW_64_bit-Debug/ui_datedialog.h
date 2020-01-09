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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;

    void setupUi(QDialog *DateDialog)
    {
        if (DateDialog->objectName().isEmpty())
            DateDialog->setObjectName(QString::fromUtf8("DateDialog"));
        DateDialog->resize(1036, 725);
        buttonBox = new QDialogButtonBox(DateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 380, 121, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        calendarWidget = new QCalendarWidget(DateDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 50, 451, 291));
        textEdit = new QTextEdit(DateDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(510, 50, 451, 451));
        textEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhSensitiveData);

        retranslateUi(DateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DateDialog);
    } // setupUi

    void retranslateUi(QDialog *DateDialog)
    {
        DateDialog->setWindowTitle(QApplication::translate("DateDialog", "Dialog", nullptr));
        textEdit->setHtml(QApplication::translate("DateDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateDialog: public Ui_DateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEDIALOG_H
