#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include<QTableView>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journal");

    db.setUserName("elton");
    db.setHostName("epica");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection()) {
        return -1;
    }

    //Creating of the data base
    QSqlQuery query;
    QString   str  = "CREATE TABLE IF NOT EXISTS mainTable ( "
                         "name TEXT, "
                         "data TEXT"
                     ");";

    if (!query.exec(str)) {
        qDebug() << "Unable to create a table";
    }

    //Adding some information
    QString strF =
          "INSERT INTO  mainTable (name, data) "
          "VALUES('%1', '%2');";

    str = strF.arg("My first planer 02.01.2019 ")
              .arg("Something is happening");

    if (!query.exec(str)) {
        qDebug() << "Unable to make insert opeation";
    }

//    str = strF.arg("4")
//              .arg("Lora")
//              .arg("+45 7845 654")
//              .arg("lora@mega.de");
//    if (!query.exec(str)) {
//        qDebug() << "Unable to make insert operation";
//    }

    if (!query.exec("SELECT * FROM mainTable;")) {
        qDebug() << "Unable to execute query - exiting";
        return 1;
    }


    //Reading of the data
//    QSqlRecord rec     = query.record();
//    int        nNumber = 0;
//    QString    strName;
//    QString    strPhone;
//    QString    strEmail;

//    while (query.next()) {
//        nNumber  = query.value(rec.indexOf("number")).toInt();
//        strName  = query.value(rec.indexOf("name")).toString();
//        strPhone = query.value(rec.indexOf("phone")).toString();
//        strEmail = query.value(rec.indexOf("email")).toString();

//        qDebug() << nNumber << " " << strName << ";\t"
//                 << strPhone << ";\t" << strEmail;
//    }


    QTableView     view;
    QSqlTableModel model;

    model.setTable("mainTable");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    view.setModel(&model);
    view.resize(450, 100);
    view.show();




    MainWindow w;

    w.show();
    return a.exec();
}
