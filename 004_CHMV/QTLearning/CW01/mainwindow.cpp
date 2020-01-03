#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datedialog.h"
#include "ui_datedialog.h"
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
    str = strF.arg("My fourth planer 02.01.2019 ")
            .arg("Too much)) is happening");
       //if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}

    if (!query.exec("SELECT * FROM mainTable ORDER BY id DESC;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query - exiting";
        //return 1;
    }
    /*
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
*/
    QSqlQueryModel * model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT * FROM mainTable ORDER BY id DESC");
    qry->exec();
    model->setQuery(*qry);          //THIS ONE WORKS(AT LEAST PUSHES THE DATA TO THE TABLEVIEW)
    ui->tableView_2->setModel(model);
    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(2);
    ui->tableView_2->setColumnWidth(1,191);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //ui->tableView_2->setModel(model);

     num = 0;
    //  Reading of the data
    QSqlRecord rec     = query.record();
    QString    namestr;
    QString    datastr;
    while (query.next()) {// $55 we have to also get it out from the query
        namestr  = query.value(rec.indexOf("name")).toString();
        datastr  = query.value(rec.indexOf("data")).toString();
        qDebug() << namestr << " - " << datastr;
        num++;//counted all the records
    }

    QSqlQuery * qryt = new QSqlQuery(db);
    qryt->prepare("SELECT * FROM mainTable");
    qryt->exec();//it can't be applied to QSqlTableModel

    QSqlTableModel* modelt = new QSqlTableModel();
    modelt->setTable("mainTable");
    modelt->setFilter("id = "+QString::number(num));
    modelt->select();
    modelt->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_3->setModel(modelt);
    ui->tableView_3->hideColumn(0);
    ui->tableView_3->hideColumn(2);
    ui->tableView_3->setColumnWidth(1,561);

    ui->tableView_4->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_4->setModel(modelt);
    ui->tableView_4->hideColumn(0);
    ui->tableView_4->hideColumn(1);
    ui->tableView_4->setColumnWidth(2,561);

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
        int idi = index.row();//returns the number of the clicked record in tableView_2
        currentRecord = (num - idi);
        QSqlTableModel* modelt = new QSqlTableModel();
        modelt->setTable("mainTable");
        modelt->setFilter("id = "+QString::number(currentRecord));
        modelt->select();
        modelt->setEditStrategy(QSqlTableModel::OnFieldChange);

        ui->tableView_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView_3->setModel(modelt);
        ui->tableView_3->hideColumn(0);
        ui->tableView_3->hideColumn(2);
        ui->tableView_3->setColumnWidth(1,561);

        ui->tableView_4->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView_4->setModel(modelt);
        ui->tableView_4->hideColumn(0);
        ui->tableView_4->hideColumn(1);
        ui->tableView_4->setColumnWidth(2,561);
}

void MainWindow::on_pushButton_clicked()
{
    //DateDialog dd;
    dd.show();
}
