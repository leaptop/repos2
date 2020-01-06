#include "datedialog.h"
#include "ui_datedialog.h"
#include "mainwindow.h"
DateDialog::DateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateDialog)
{
    ui->setupUi(this);
}

DateDialog::~DateDialog()
{
    delete ui;
}
void DateDialog::on_buttonBox_accepted()
{
    QDate qd = ui->calendarWidget->selectedDate();
    QString str = qd.toString(Qt::ISODateWithMs);//declared a string with a date value
    QString st = ui->textEdit->toPlainText();//declared a string with a text from QtextEdit
    QString  strF =//declared a string with special fields %2, %3, that might be replaced by using the arg()function
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    str = strF.arg(str)//redefining the string str with a value of strF and new added via the arg() function data(of str and st values)
            .arg(st);
    QSqlQuery query ;//I wouldn't redefine str, but would have redefined strF and put it in the exec() call
    if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}//it would still work.
    emit (needToReloadTable());

}
