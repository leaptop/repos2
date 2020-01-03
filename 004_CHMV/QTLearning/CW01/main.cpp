#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include<QTableView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    MainWindow w;

    w.show();
    return a.exec();
}
