#include "mainwindow.h"

#include <QApplication>
#include <QtSql>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("addressbook");

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
    }else
        QSqlQuery query;

   // if()
    //Creating of the data base
    QSqlQuery query;
   // QString str0 = "CREATE TABLE IF NOT EXISTS";
   // if(!query.exec())
    QString   str  = "CREATE TABLE IF NOT EXISTS addressbook ( "
                         "number INTEGER PRIMARY KEY NOT NULL, "
                         "name   VARCHAR(15), "
                         "phone  VARCHAR(12), "
                         "email  VARCHAR(15) "
                     ");";

    if (!query.exec(str)) {
        qDebug() << "Unable to create a table";
    }

    //Adding some information
    QString strF =
          "INSERT INTO  addressbook (number, name, phone, email) "
          "VALUES(%1, '%2', '%3', '%4');";

    str = strF.arg("3")
              .arg("Shtefan")
              .arg("+7 913 389 51 27")
              .arg("stnAlv@mega.de");
    if (!query.exec(str)) {
        qDebug() << "Unable to make insert opeation";
    }

    str = strF.arg("4")
              .arg("Lora")
              .arg("+45 7845 654")
              .arg("lora@mega.de");
    if (!query.exec(str)) {
        qDebug() << "Unable to make insert operation";
    }

    if (!query.exec("SELECT * FROM addressbook;")) {
        qDebug() << "Unable to execute query - exiting";
        return 1;
    }

    //Reading of the data
    QSqlRecord rec     = query.record();
    int        nNumber = 0;
    QString    strName;
    QString    strPhone;
    QString    strEmail;

    while (query.next()) {
        nNumber  = query.value(rec.indexOf("number")).toInt();
        strName  = query.value(rec.indexOf("name")).toString();
        strPhone = query.value(rec.indexOf("phone")).toString();
        strEmail = query.value(rec.indexOf("email")).toString();

        qDebug() << nNumber << " " << strName << ";\t"
                 << strPhone << ";\t" << strEmail;
    }




    MainWindow w;
    w.show();
    return a.exec();
}
