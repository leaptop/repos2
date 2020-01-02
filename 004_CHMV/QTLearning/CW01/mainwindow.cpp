#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    //  if (!createConnection()) {//(return -1; previously)

    //  }
    //    QTableView     view;
    //  QSqlTableModel model;

    //    model.setTable("mainTable");
    //    model.select();
    //    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    //    view.setModel(&model);
    //    view.resize(450, 100);
    //    view.show();
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

    str = strF.arg("My third planer 02.01.2019 ")
            .arg("Something is happening");

    //  if (!query.exec(str)) {
    //     qDebug() << "Unable to make insert opeation";
    //  }

    if (!query.exec("SELECT * FROM mainTable;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query - exiting";
        //return 1;
    }
    QSqlQueryModel * modal = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT name FROM mainTable");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

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
