#include "dayeditdialog.h"
#include "ui_dayeditdialog.h"
//#include "mainwindow.h"
#include<QSqlQuery>
#include <QDebug>

dayEditDialog::dayEditDialog(QString str,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dayEditDialog)
{//this constructor isn't called for some reason. No it was called. It just was called in time of MainWindow initiation.
    //So the function dd.show() in the button just showed the ready object.
    //Now I'm trying to create new objects of the dialog window every time, but still can't get the text. Even though
    //the constructor works - qDebug from the constructor writes in a console.
    //... No. Everything is implemented already.
    ui->setupUi(this);
    //the text gets here(in dateedit.h), but I can't put it in the textEdit...
   // ui->textEdit->setText(anOldText);//the program breaks somewhere
    //qDebug()<<"pause";
   // qDebug()<<anOldText;//anOldText is an empty string at this point
    ui->textEdit->setText(str);
}
//To return to your desired branch and see everything as it was you always need to use -f:

dayEditDialog::~dayEditDialog()
{
    delete ui;
}

void dayEditDialog::on_pushButton_clicked()
{
    QSqlQuery query ;
    QString   str;
    QString st = ui->textEdit->toPlainText();
    QString  strF = "UPDATE  mainTable SET data = '"+st+"' WHERE id = "+QString::number(changedRecord);
    if (!query.exec(strF)){qDebug() << "Unable to make insert opeation in dayEditDialog on_pushButton_clicked() ";}
       // emit (needToReloadTable());
}

void dayEditDialog::on_pushButton_2_clicked()
{
    //ui->textEdit->setText(anOldText);
}
