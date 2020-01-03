#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    // ui->tableView.

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journal");

    db.setUserName("elton");
    db.setHostName("epica");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        int n =
                QMessageBox::warning(0,"Warning" ,   "createConnection() = false",
                                     "Ok",
                                     0
                                     );
        if (!n) {
            // Saving the changes!
        }
    }
    //Creating of the data base
    QSqlQuery query;
    QString   str  = "CREATE TABLE IF NOT EXISTS mainTable ( "
                     "id INTEGER primary key AUTOINCREMENT, "
                     "name TEXT, "
                     "data TEXT"
                     ");";

    if (!query.exec(str)) {
        qDebug() << "Unable to create a table";
    }

    //Adding some information
    QString strF =
            "INSERT INTO  mainTable (name, data) "
            "VALUES('%2', '%3');";

    str = strF.arg("My third planer 02.01.2019 ")
            .arg("Everything is happening");

    //if (!query.exec(str)) {qDebug() << "Unable to make insert opeation";}

    if (!query.exec("SELECT * FROM mainTable;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query - exiting";
        //return 1;
    }
    QSqlQueryModel * model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    //modal.setEd
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT name FROM mainTable");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView_2->setModel(model);
    ui->tableView_2->setColumnWidth(0,191);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);





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
}

MainWindow::~MainWindow()
{
    delete ui;
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
    qDebug()<< index.row() << " was doubleClicked";// was the value of index.row
    int idi = index.row();
    QSqlQuery query;
    if (!query.exec("SELECT data FROM mainTable WHERE id = "+QString::number(idi+1))) {
        qDebug() << "Unable to execute query - exiting";
    }
    QSqlRecord rec     = query.record();
    QString    namestr;
    QString    datastr;
    query.next();
    ui->textEdit->setText(query.value(rec.indexOf("data")).toString());
}
void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    //qDebug()<< index.row() << " was clicked once";
}
