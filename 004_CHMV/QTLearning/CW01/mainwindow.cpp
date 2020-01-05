#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datedialog.h"
#include "ui_datedialog.h"
//#include<HelpBrowser.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    reloadTable();
    //hb(":/htmFiles/Common", "index.htm");
    QObject::connect(&dd, SIGNAL(needToReloadTable()),
                     SLOT(reloadTable()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::reloadTable(){
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
    if (!query.exec("SELECT * FROM mainTable ORDER BY id DESC;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query - exiting";
        //return 1;
    }
    QSqlQueryModel * model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT * FROM mainTable ORDER BY id DESC");
    qry->exec();
    model->setQuery(*qry);          //THIS ONE WORKS(AT LEAST PUSHES THE DATA TO THE TABLEVIEW)
    ui->tableView_2->setModel(model);
    //ui-->setModel(model);
    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(2);
    ui->tableView_2->setColumnWidth(1,191);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    numOfRecords = 0;
    //  Reading of the data
    QSqlRecord rec     = query.record();
    QString    namestr;
    QString    datastr;
    while (query.next()) {// $55 we have to also get it out from the query
        namestr  = query.value(rec.indexOf("name")).toString();
        qsl+=  datastr  = query.value(rec.indexOf("data")).toString();
        qDebug() << namestr << " - " << datastr;
        numOfRecords++;//counted all the records
    }
    QString lastData = qsl[0];
    qDebug()<<"qsl[0] = "<<qsl[0];
    QSqlTableModel* modelt = new QSqlTableModel();
    modelt->setTable("mainTable");
    modelt->setFilter("id = "+QString::number(numOfRecords));
    modelt->select();
    modelt->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_3->setModel(modelt);
    ui->tableView_3->hideColumn(0);
    ui->tableView_3->hideColumn(2);
    ui->tableView_3->setColumnWidth(1,561);

    ui->textEdit->setText(qsl[0]);
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
    currentRecord = (numOfRecords - idi);
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

    ui->textEdit->setText(qsl[idi]);
}

void MainWindow::on_pushButton_clicked()//new record clicked
{
    dd.show();
}

void MainWindow::on_pushButton_2_clicked()//reload table clicked
{
    reloadTable();
}

void MainWindow::on_pushButton_3_clicked()//help clicked
{
    hd.show();
}
