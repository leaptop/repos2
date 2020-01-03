#include "datedialog.h"
#include "ui_datedialog.h"

DateDialog::DateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateDialog)
{
    ui->setupUi(this);
    QString  strF =
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    QSqlQuery query ;
    QString   str;

//    str = strF.arg(calendarWidget->)
//            .arg("some activity");
//       if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}

}

DateDialog::~DateDialog()
{
    delete ui;
}

void DateDialog::on_buttonBox_accepted()
{
    QDate qd = ui->calendarWidget->selectedDate();
    QSqlQuery query ;
    QString   str;
    str = qd.toString(Qt::ISODate);
    qDebug()<<str;

}
