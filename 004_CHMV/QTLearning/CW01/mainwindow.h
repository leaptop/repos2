#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datedialog.h"
#include "helpdialog.h"
#include "dayeditdialog.h"
#include <QMainWindow>
#include <QApplication>
#include <QtSql>
#include<QTableView>
#include<QMessageBox>
#include <QtWidgets>

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
    int numOfRecords = 0;//number of records
    QSqlTableModel model;
    DateDialog dd;
    HelpDialog hd;
    bool createConnection();
    void helpNavigator();
    QStringList qsl;//a list of data column
    int currRecId = 0;
    int numOfRecordsByRowCount = 0;
    //QComboBox*    pcbo;
    dayEditDialog ded;

signals:
    void  helpClicked();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void reloadTable();

    void slot1Help();

    void slotChangeStyle(const QString& str);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
