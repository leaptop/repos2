#include "dayeditdialog.h"
#include "ui_dayeditdialog.h"
//#include "mainwindow.h"
#include<QSqlQuery>

dayEditDialog::dayEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dayEditDialog)
{
    ui->setupUi(this);
    //ui->textEdit->setText(anOldText);//the program breaks somewhere
}

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
    if (!query.exec(strF)){} //{qDebug() << "Unable to make insert opeation in dayEditDialog on_pushButton_clicked() ";}
       // emit (needToReloadTable());
}
