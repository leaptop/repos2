#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include<QTableView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    MainWindow w;
 //   DateDialog dd;
   // dd.setParent(&w);//it adds the contents of dd
    //straight into MainWindow w!!! Funny looking picture

    w.show();
    return a.exec();
}
