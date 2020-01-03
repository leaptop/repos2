#include "datedialog.h"
#include "ui_datedialog.h"

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
    QSqlQuery query ;
    QString   str;
    str = qd.toString(Qt::ISODateWithMs);
    qDebug()<<"\n"<<str;
    QString  strF =
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    str = strF.arg(str)
            .arg("some activity");
    if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}


}
