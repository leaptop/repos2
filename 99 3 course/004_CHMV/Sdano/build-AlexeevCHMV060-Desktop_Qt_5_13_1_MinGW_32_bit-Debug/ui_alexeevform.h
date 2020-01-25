/********************************************************************************
** Form generated from reading UI file 'alexeevform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALEXEEVFORM_H
#define UI_ALEXEEVFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlexeevForm
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QWidget *AlexeevForm)
    {
        if (AlexeevForm->objectName().isEmpty())
            AlexeevForm->setObjectName(QString::fromUtf8("AlexeevForm"));
        AlexeevForm->resize(400, 300);
        AlexeevForm->setStyleSheet(QString::fromUtf8("lBLA"));
        label = new QLabel(AlexeevForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 47, 13));
        textEdit = new QTextEdit(AlexeevForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(220, 60, 161, 141));
        buttonBox_2 = new QDialogButtonBox(AlexeevForm);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(100, 240, 271, 23));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);

        retranslateUi(AlexeevForm);

        QMetaObject::connectSlotsByName(AlexeevForm);
    } // setupUi

    void retranslateUi(QWidget *AlexeevForm)
    {
        AlexeevForm->setWindowTitle(QCoreApplication::translate("AlexeevForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("AlexeevForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlexeevForm: public Ui_AlexeevForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALEXEEVFORM_H
