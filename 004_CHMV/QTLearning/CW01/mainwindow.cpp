#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journey");

    db.setUserName("elton");
    db.setHostName("epica");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        int n =
                QMessageBox::warning(0,"Warning" ,   "createConnection() = false",
                                     "Ok", 0  );
        if (!n) {
            // Saving the changes!
        }
    }
    //Creating of the data base
    QSqlQuery query;
   QString str  = "CREATE TABLE IF NOT EXISTS mainTable ( "
                     "id INTEGER primary key AUTOINCREMENT, "
                     "name TEXT, "
                     "data TEXT"
                     ");";

    if (!query.exec(str)) {//couldn't find sql driver->returned false
        qDebug() << "Unable to create a table";
    }




    //Adding some information
   QString  strF =
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";
    str = strF.arg("My second planer 02.01.2019 ")
            .arg("Something is happening");
 //   if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}

    if (!query.exec("SELECT * FROM mainTable ORDER BY id DESC;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query - exiting";
        //return 1;
    }
//if (!MainWindow::createConnection()) { qDebug()<<"couldn't cReAtE connection";  }

    //QTableView     view;//needed to comment it, because the memory stack  disappears when the constructor
    //ends implementing its funtions and fields, including view. So view disappeared momentarily before commenting.
//    QSqlTableModel model0;
//    model0.setTable("mainTable");//seems like its impossible to choose certain fields,
//    //using QSqlTableModel...
//   // model0.setSort(0, Qt::DescendingOrder);//this is how to sort
//    model0.select();
//    model0.setEditStrategy(QSqlTableModel::OnFieldChange);

//ui->tableView_2->setModel(&model0);
////ui->tableView_2->hideColumn(0);
////ui->tableView_2->hideColumn(2);
//ui->tableView_2->setSortingEnabled(true);
//ui->tableView_2->setColumnWidth(0,191);
//ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

//    view.setModel(&model0);
//    //view.hideColumn(0);//but its possible to hide them here
//    //view.hideColumn(2);
//    view.resize(450, 100);
//    view.show();
/*
    QSqlQueryModel * model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT name FROM mainTable ORDER BY id DESC");
    qry->exec();
    model->setQuery(*qry);          //THIS ONE WORKS(AT LEAST PUSHES THE DATA TO THE TABLEVIEW)
    ui->tableView_2->setModel(model);
    //ui->tableView_2->sortByColumn(0,Qt::AscendingOrder);
   // ui->tableView_2->setSortingEnabled(true);
    ui->tableView_2->setColumnWidth(0,191);
   // ui->tableView_2->hideColumn(0);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//ui->tableView_2->setModel(model);
*/
    QSqlQueryModel * model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT * FROM mainTable ORDER BY id DESC");
    qry->exec();
    model->setQuery(*qry);          //THIS ONE WORKS(AT LEAST PUSHES THE DATA TO THE TABLEVIEW)
    ui->tableView_2->setModel(model);
    //ui->tableView_2->sortByColumn(0,Qt::AscendingOrder);
   // ui->tableView_2->setSortingEnabled(true);

    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(2);
    ui->tableView_2->setColumnWidth(1,191);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//ui->tableView_2->setModel(model);

        //  Reading of the data
        QSqlRecord rec     = query.record();
        QString    namestr;
        QString    datastr;
        while (query.next()) {// $55 we have to also get it out from the query
            namestr  = query.value(rec.indexOf("name")).toString();
            datastr  = query.value(rec.indexOf("data")).toString();
            qDebug() << namestr << " - " << datastr;
            //ui->tableView->;
        }

       // QTableView     view;
//        QSqlTableModel model;

//        model.setTable("mainTable");
//        model.select();
//        model.setEditStrategy(QSqlTableModel::OnFieldChange);

//        view.setModel(&model);
//        view.resize(450, 100);
//        view.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
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
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    //QtableView qtbl = new QtableView(this);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{// this is how to get an index of the chosen field of tableView
    qDebug()<< index.row() << " was the value of index.row";
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{

}
int currentRecord = 0;
void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{


    //    // qDebug()<< index.row() << " was doubleClicked";// was the value of index.row
    //    int idi = index.row();//returns the number of the clicked record in tableView_2
    //    currentRecord = idi+1;
    //   // index.
    //    QSqlQuery query;
    //    if (!query.exec("SELECT * FROM mainTable WHERE id = "+QString::number(idi+1))) {
    //        qDebug() << "Unable to execute query - exiting";
    //    }//pushed the query to the query class and executed it(took the fields of clicked(idi)
    //    // records of tableView_2
    //    QSqlRecord rec = query.record();//some magic with QSqlRecord
    //    query.next();//in the beginning it was inside of a loop
    //    //but now I know, that there will be just one record taken
    //    ui->textEdit->setText(query.value(rec.indexOf("data")).toString());
    //    ui->textEdit_2->setText(query.value(rec.indexOf("name")).toString());


}

void MainWindow::on_pushButton_clicked()
{
    //    QSqlTableModel model;
    //    model.setTable("mainTable");
    //    model.record(currentRecord).insert()
    //    model.setEditStrategy(QSqlTableModel::OnFieldChange);
    //    ui->textEdit_2->get
}
