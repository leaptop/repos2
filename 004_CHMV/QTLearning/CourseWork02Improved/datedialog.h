#ifndef DATEDIALOG_H
#define DATEDIALOG_H
//#include "mainwindow.h"//it introduces a circular dependency
#include <QDialog>
#include<QCalendarWidget>
#include<QSqlQuery>
#include <QtSql>
#include<QTableView>
#include<QMessageBox>

namespace Ui {
class DateDialog;
}

class DateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateDialog(QWidget *parent = nullptr);
    ~DateDialog();
    QCalendarWidget cw;
    QDate qd;
    QString str;
    QString st;
    QString  strF;
    QSqlQuery query;


public slots:
    void on_buttonBox_accepted();

 signals:
   void needToReloadTable();

private slots:
   void on_pushButton_clicked();

   void on_calendarWidget_selectionChanged();

private:
    Ui::DateDialog *ui;
};

#endif // DATEDIALOG_H
