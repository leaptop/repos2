#include "datedialog.h"
#include "ui_datedialog.h"
#include "mainwindow.h"
DateDialog::DateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateDialog)
{
    ui->setupUi(this);
    //reloadTable();
}

DateDialog::~DateDialog()
{
    delete ui;
}
void DateDialog::on_buttonBox_accepted()
{
    //MainWindow mw = this;
    QDate qd = ui->calendarWidget->selectedDate();
    QSqlQuery query ;
    QString   str;
    str = qd.toString(Qt::ISODateWithMs);
    qDebug()<<"\n"<<str;
    QString st = ui->plainTextEdit->toPlainText();
    QString  strF =
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    str = strF.arg(str)
            .arg(st);
    if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}
 emit SIGNAL("clocked");
   // parent()->


}
