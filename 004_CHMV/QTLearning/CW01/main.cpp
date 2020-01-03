#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include<QTableView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // if (!createConnection()) { return -1;  }

//    QTableView     view;
//    QSqlTableModel model0;

//    model0.setTable("mainTable");//seems like its impossible to choose certain fields,
//    //using QSqlTableModel...
//    model0.setSort(0, Qt::DescendingOrder);//this is how to sort
//    model0.setFilter("id  = '2'");//this is how to filter
//    //model0->setQuery("SELECT name FROM mainTable");//doesn't work
//    //model0.selectStatement()//not sure how it works
//    model0.select();
//    model0.setEditStrategy(QSqlTableModel::OnFieldChange);

//    view.setModel(&model0);
//    view.hideColumn(0);//but its possible to hide them here
//    view.resize(450, 100);
//    view.show();



    MainWindow w;

    w.show();
    return a.exec();
}
