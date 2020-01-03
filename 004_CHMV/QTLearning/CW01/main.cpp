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

    QTableView     view;
    QSqlTableModel model0;

    model0.setTable("mainTable");
    model0.setSort(0, Qt::DescendingOrder);
    model0.setFilter("id  = '2'");
    model0.select();
    model0.setEditStrategy(QSqlTableModel::OnFieldChange);

    view.setModel(&model0);
    view.resize(450, 100);
    view.show();



    MainWindow w;

    w.show();
    return a.exec();
}
