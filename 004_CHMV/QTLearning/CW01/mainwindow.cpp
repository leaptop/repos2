#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datedialog.h"
#include "ui_datedialog.h"
#include "dayeditdialog.h"
#include "ui_dayeditdialog.h"
//#include<HelpBrowser.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{                                       //CONSTRUCTOR
    ui->setupUi(this);
    reloadTable();
    QObject::connect(&dd, SIGNAL(needToReloadTable()),//connecting signal from dateDialog
                     SLOT(reloadTable()));
//    QObject::connect(&ded, SIGNAL(needToReloadTable()),//connecting signal from dayEditDialog
//                     SLOT(reloadTable()));

    ui->comboBox->addItems(QStyleFactory::keys());
    ui->comboBox->addItem("style.qss(mine)");
    ui->comboBox->addItem("basic");
    connect(ui->comboBox,
            SIGNAL(activated(const QString&)),   //style changes
            SLOT(slotChangeStyle(const QString&))
            );
}
void MainWindow::slotChangeStyle(const QString& str)
{
    QStyle* pstyle = QStyleFactory::create(str);
    if(str=="style.qss(mine)"){
        QFile file(":/styles/Common/style.qss");//this is how to use resource files
        file.open(QFile::ReadOnly);
        QString strCSS = QLatin1String(file.readAll());
        qApp->setStyleSheet(strCSS);//uncomment to apply changes from a qss file
    }else if(str=="basic"){
        qApp->setStyleSheet("");
    }else
        QApplication::setStyle(pstyle);
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
    }
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

    qsl.clear();
    numOfRecords = 0;
    //  Reading of the data
    QSqlRecord rec     = query.record();
    QString    namestr;
    QString    datastr;
    while (query.next()) {// $55 we have to also get it out from the query
        //  namestr  = query.value(rec.indexOf("name")).toString();
        qsl+=  datastr  = query.value(rec.indexOf("data")).toString();
        // qDebug() << namestr << " - " << datastr;
        numOfRecords++;//counted all the records
    }
    numOfRecordsByRowCount = model->rowCount();
    if(!(numOfRecords==numOfRecordsByRowCount))qDebug()<<"num of records counted wrong";
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

    QSqlTableModel* modelt2 = new QSqlTableModel();//uncommenting it will show all the table in a separate view
    modelt2->setTable("mainTable");
    modelt2->select();
    if(!modelt2->submitAll()){
        qDebug()<<"couldn't submitAll";
    }
    view.setModel(modelt2);
    view.show();
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
    ded.changedRecord = currRecId;//inserted the needed ID to change from a new ded dialog window
    ded.anOldText = ui->textEdit->toPlainText();//inserted current text to edit
    ded.show();
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)//clicked tableView_2
{
    int idi = index.row();//returns the number of the clicked record in tableView_2(by order starting from top)
    //finally understood how to retreive id's from tableView. It's done through it's sibling by coordinates:
    currRecId = (ui->tableView_2->model()->data(ui->tableView_2->model()->sibling(idi, 0, index))).toInt();
    QSqlTableModel* modelt = new QSqlTableModel();
    modelt->setTable("mainTable");
    modelt->setFilter("id = "+QString::number(currRecId));
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

void MainWindow::on_pushButton_4_clicked()//save changes
{
    QSqlQuery query ;
    QString   str;
    QString st = ui->textEdit->toPlainText();
    QString  strF = "UPDATE  mainTable SET data = '"+st+"' WHERE id = "+QString::number(currRecId);
    if (!query.exec(strF)) {qDebug() << "Unable to make insert opeation in push button 4";}
    reloadTable();
}
void MainWindow::slot1Help(){
    hd.show();
}

void MainWindow::on_pushButton_5_clicked()//delete the chosen record
{
    QSqlQuery query ;
    QString   str;
    str = "DELETE FROM mainTable WHERE id = '"+QString::number(currRecId)+"';";
    if(!query.exec(str)){
        qDebug()<<"couldn't delete from on_pushButton_5_clicked()";
    }
    reloadTable();
}

