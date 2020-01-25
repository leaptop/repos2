#ifndef STARTDIALOG_ALEXEEV_H
#define STARTDIALOG_ALEXEEV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog.h"

class startdialog_alexeev : public QPushButton
{
    Q_OBJECT
public:
    startdialog_alexeev(QWidget* pwgt = 0) : QPushButton("Нажми", pwgt){
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        InputDialog* pInputDialog = new InputDialog;
        if (pInputDialog->exec()==QDialog::Accepted){
            QMessageBox::information(0,
                                     "Ваша информация: ",
                                     "Имя: "
                                     +pInputDialog->firstName()
                                     +"\nФамилия: "
                                     +pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};


#endif // STARTDIALOG_ALEXEEV_H
