/********************************************************************************
** Form generated from reading UI file 'alexeev.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALEXEEV_H
#define UI_ALEXEEV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alexeev
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QWidget *alexeev)
    {
        if (alexeev->objectName().isEmpty())
            alexeev->setObjectName(QString::fromUtf8("alexeev"));
        alexeev->resize(575, 409);
        buttonBox = new QDialogButtonBox(alexeev);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(243, 324, 311, 23));
        buttonBox->setStyleSheet(QString::fromUtf8("background:rgb(224, 226, 255)"));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);
        textEdit = new QTextEdit(alexeev);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(236, 43, 318, 275));
        textEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";"));

        retranslateUi(alexeev);

        QMetaObject::connectSlotsByName(alexeev);
    } // setupUi

    void retranslateUi(QWidget *alexeev)
    {
        alexeev->setWindowTitle(QApplication::translate("alexeev", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alexeev: public Ui_alexeev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALEXEEV_H
