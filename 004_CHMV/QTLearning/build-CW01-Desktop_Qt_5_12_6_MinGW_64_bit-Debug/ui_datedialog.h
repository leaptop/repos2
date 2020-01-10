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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DateDialog
{
public:
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *DateDialog)
    {
        if (DateDialog->objectName().isEmpty())
            DateDialog->setObjectName(QString::fromUtf8("DateDialog"));
        DateDialog->resize(1146, 505);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/Common/iconSmall24.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DateDialog->setWindowIcon(icon);
        calendarWidget = new QCalendarWidget(DateDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 50, 451, 291));
        textEdit = new QTextEdit(DateDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(500, 50, 621, 421));
        textEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhSensitiveData);
        pushButton = new QPushButton(DateDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(950, 480, 171, 21));
        textEdit_2 = new QTextEdit(DateDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(500, 10, 621, 31));

        retranslateUi(DateDialog);

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
        pushButton->setText(QApplication::translate("DateDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateDialog: public Ui_DateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEDIALOG_H
