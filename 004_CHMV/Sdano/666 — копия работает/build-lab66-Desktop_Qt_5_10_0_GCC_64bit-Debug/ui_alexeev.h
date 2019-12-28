/********************************************************************************
** Form generated from reading UI file 'alexeev.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_alexeev_H
#define UI_alexeev_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alexeev
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *alexeev)
    {
        if (alexeev->objectName().isEmpty())
            alexeev->setObjectName(QStringLiteral("alexeev"));
        alexeev->resize(575, 409);
        buttonBox = new QDialogButtonBox(alexeev);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 324, 524, 23));
        buttonBox->setStyleSheet(QStringLiteral("background:rgb(224, 226, 255)"));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);
        textEdit = new QTextEdit(alexeev);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(236, 43, 318, 275));
        textEdit->setStyleSheet(QStringLiteral("font: 10pt \"xos4 Terminus\";"));
        label = new QLabel(alexeev);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 80, 200, 200));
        label->setMinimumSize(QSize(200, 0));
        label->setMaximumSize(QSize(200, 200));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);

        retranslateUi(alexeev);

        QMetaObject::connectSlotsByName(alexeev);
    } // setupUi

    void retranslateUi(QWidget *alexeev)
    {
        alexeev->setWindowTitle(QApplication::translate("alexeev", "Form", nullptr));
        label->setText(QApplication::translate("alexeev", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alexeev: public Ui_alexeev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_alexeev_H
