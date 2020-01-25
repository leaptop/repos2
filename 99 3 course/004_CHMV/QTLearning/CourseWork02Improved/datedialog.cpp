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
void DateDialog::on_buttonBox_accepted(){}

void DateDialog::on_pushButton_clicked()
{
    //WHAT INTERESTING IS THAT I CAN QUERY MY DATABASE FROM HERE, IT'S VISIBLE, BUT CAN'T CALL FUNCTIONS OF MainWindow. WHY IS THAT?
    str = ui->textEdit_2->toPlainText();
    st = ui->textEdit->toPlainText();//declared a string with a text from QtextEdit
    strF =//declared a string with special fields %2, %3, that might be replaced by using the arg()function
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    str = strF.arg(str)//redefining the string str with a value of strF and new added via the arg() function data(of str and st values)
            .arg(st);
    QSqlQuery  query ;//I wouldn't redefine str, but would have redefined strF and put it in the exec() call
    if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}//it would still work.
    emit (needToReloadTableAfterDateDialog());
     //qmw->ui->tableView_2->selectRow(0);
}

void DateDialog::on_calendarWidget_selectionChanged()
{
    qd = ui->calendarWidget->selectedDate();
    str = qd.toString(Qt::ISODateWithMs);//declared a string with a date value
    ui->textEdit_2->setText(str);
}
