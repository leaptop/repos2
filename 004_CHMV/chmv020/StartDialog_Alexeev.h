#ifndef STARTDIALOG_ALEXEEV_H
#define STARTDIALOG_ALEXEEV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "InputDialog_Alexeev.h"

class StartDialog_Alexeev: public QPushButton{
    Q_OBJECT
public:
    StartDialog_Alexeev(QWidget* pwgt = 0) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked(){
        InputDialog_Alexeev* pInputDialog = new InputDialog_Alexeev;
        if (pInputDialog->exec() == QDialog::Accepted){
            QMessageBox::information(0,
                                     "Ваша информация: ",
                                     "Имя: "
                                     + pInputDialog->firstName()
                                     +"\nФамилия: "
                                     + pInputDialog->lastName()
                                     );
        }
        delete pInputDialog;
    }

};

#endif // STARTDIALOG_ALEXEEV_H
