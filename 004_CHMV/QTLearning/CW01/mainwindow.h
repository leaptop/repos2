#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datedialog.h"
#include <QMainWindow>
#include <QApplication>
#include <QtSql>
#include<QTableView>
#include<QMessageBox>
//class DateDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;//somehow it allows me to adress my db from a slot,
    //even though it was declared aninstantiated in a constructor
    QTableView     view;
    QSqlTableModel model0;
    QString strF;
    QSqlQuery query ;
    QString   str;
    int num = 0;//number of records
    QSqlTableModel model;
    DateDialog dd;
    //private signals:
    void sig();
    bool createConnection();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
