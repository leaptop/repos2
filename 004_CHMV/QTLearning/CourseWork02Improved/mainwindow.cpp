#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datedialog.h"
#include "ui_datedialog.h"
#include "dayeditdialog.h"
#include "ui_dayeditdialog.h"
//#include <HtmlHighlighter>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{                                       //CONSTRUCTOR
    ui->setupUi(this);
    createConnection();
    reloadTable();
    QObject::connect(&dd, SIGNAL(needToReloadTableAfterDateDialog()),//connecting signal from dateDialog
                     SLOT(reloadTableAfterDateDialog()));

    ui->comboBox->addItems(QStyleFactory::keys());
    ui->comboBox->addItem("style.qss(mine)");
    ui->comboBox->addItem("delete style");
    connect(ui->comboBox,
            SIGNAL(activated(const QString&)),   //style changes
            SLOT(slotChangeStyle(const QString&))
            );
    //ui->textEdit->setHtml("<b>много важных дел</b>");//HTML WORKS!!!
}
QTextCursor MainWindow::textCursor()
{
    return ui->textEdit->textCursor();
}
void MainWindow::on_pushButton_6_clicked()//strikethrough pushed
{
    QTextCursor tc = textCursor();
    QTextCharFormat format = tc.charFormat();
    format.setFontStrikeOut( !format.fontStrikeOut() );
    tc.setCharFormat(format);
}
void MainWindow::slotChangeStyle(const QString& str)//it gets a string str from QComboBox and creates styles as I want down below
{
    QStyle* pstyle = QStyleFactory::create(str);
    if(str=="style.qss(mine)"){
        QFile file(":/styles/Common/style.qss");//this is how to use resource files
        file.open(QFile::ReadOnly);
        QString strCSS = QLatin1String(file.readAll());
        qApp->setStyleSheet(strCSS);//uncomment to apply changes from a qss file
    }else if(str=="delete style"){
        qApp->setStyleSheet("");//resetting the style to "basic"
    }else
        QApplication::setStyle(pstyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::reloadTableAfterDateDialog(){
    // currTableViewId = 0;
    reloadTable();
    // ui->tableView_2->selectRow(currTableViewId);//i should implement it only when I will be able to change textEdits also. Sounds easy, but I don't want to query my db for some reason. It seems too much code... but it's stupid...

}
void MainWindow::reloadTable(){
    if (!query.exec("SELECT * FROM mainTable ORDER BY id DESC;")) {//we select here, but its not all $55
        qDebug() << "Unable to execute query(in reloadTable()) - exiting ";
    }
    model = new QSqlQueryModel();//here I implemented putting of ifrst column in the tableView. Do I need it?
    QSqlQuery* qry = new QSqlQuery(db);
    qry->prepare("SELECT * FROM mainTable ORDER BY id DESC");
    qry->exec();
    model->setQuery(*qry);          //THIS ONE WORKS(AT LEAST PUSHES THE DATA TO THE TABLEVIEW)

    ui->tableView_2->setModel(model);
    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(2);
    ui->tableView_2->setColumnWidth(1,191);
    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

   // ui->textEdit_2->setText("");
    //ui->tableView_2->setse
    //    QSqlTableModel* modelt2 = new QSqlTableModel();//uncommenting it will show all the table in a separate view
    //    modelt2->setTable("mainTable");
    //    modelt2->select();
    //    if(!modelt2->submitAll()){
    //        qDebug()<<"couldn't submitAll";
    //    }
    //    view.setModel(modelt2);
    //    view.show();
}

void MainWindow::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journey");

    db.setUserName("elton");
    db.setHostName("epica");
    db.setPassword("password");
    if (!db.open()) {
        qDebug() << "Cannot open database(in createConnection()):" << db.lastError();
        int n =
                QMessageBox::warning(nullptr,"Warning" ,   "createConnection() = false",
                                     "Ok", nullptr  );
        if (!n) {            /*Saving the changes!*/     }
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
}
void MainWindow::on_tableView_activated(const QModelIndex &index){}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{// this is how to get an index of the chosen field of tableView
    qDebug()<< index.row() << " was the value of index.row";
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    QString str = ui->textEdit->toPlainText();
    QString str2 = ui->textEdit_2->toPlainText();
    //ui->textEdit->to
    ded = new dayEditDialog(str, str2);
    ded->changedRecord = currRecId;//inserted the needed ID to change from a new ded dialog window
    // ded->anOldText = ui->textEdit->toPlainText();//inserted current text to edit//
    //it works, but the constructor can't build the string IN TIME(вовремя) to pass it to it's textEdit
    ded->show();
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)//clicked tableView_2
{
    int idi = index.row();//returns the number of the clicked record in tableView_2(by order starting from top)
    //finally understood how to retreive id's from tableView. It's done through it's sibling by coordinates:
    currRecId = (ui->tableView_2->model()->data(ui->tableView_2->model()->sibling(idi, 0, index))).toInt();
    ui->textEdit_2->setText((ui->tableView_2->model()->data(ui->tableView_2->model()->sibling(idi, 1, index))).toString());
    ui->textEdit->setText((ui->tableView_2->model()->data(ui->tableView_2->model()->sibling(idi, 2, index))).toString());//THE WORKING CODE
    currTableViewId = index.row();
    ui->tableView_2->selectRow(currTableViewId);//SEARCHED THE INTERNET FOR 3 HOURS BEFORE FINDING THIS FUNCTION BY MYSELF ACCIDENTALLY AS USUAL...
}

void MainWindow::on_pushButton_clicked()//new record clicked
{
    dd.show();
}

void MainWindow::on_pushButton_2_clicked()//"reload table" clicked
{
    reloadTable();
    //ui->textEdit->setText("");//uncommenting it breaks something... the name and the data fields become empty in the db itself
   // ui->textEdit_2->setText("");//uncommenting it breaks something... the name and the data fields become empty in the db itself
    // ui->tableView_3->hideColumn(1);
}

void MainWindow::on_pushButton_3_clicked()//Font clicked
{

    bool bOK;                     //Font choice
    QFont fnt = QFontDialog::getFont(&bOK, this);//assigning a font to the fnt variable
    if(!bOK){/*the cancel button was pressed*/ } else return;
    //ui->textEdit->//setFont(fnt);//sets the font to the entire textEdit
    QTextCharFormat entityFormat;

}
void MainWindow::on_textEdit_2_textChanged()//changes the db after the text was changed in the header
{//(the name field of my db)
    QSqlQuery query;
    QString str;
    QString st = ui->textEdit_2->toPlainText();
    QString strF = "UPDATE mainTable SET name = '"+st+"' WHERE id = "+QString::number(currRecId);
    if(!query.exec(strF)) {qDebug() << "Unable to make insert operation after changing text in textEdit_2";}
    reloadTable();
    ui->tableView_2->selectRow(currTableViewId);
    //ui->tableView_2->
}

void MainWindow::on_textEdit_textChanged()//instead of pushing button "save changes" I will just
{//update the table after each correction
    QSqlQuery query ;
    QString   str;
    QString st = ui->textEdit->toPlainText();
    QString  strF = "UPDATE  mainTable SET data = '"+st+"' WHERE id = "+QString::number(currRecId);
    if (!query.exec(strF)) {qDebug() << "Unable to make insert opeation on_textEdit_textChanged()";}
}
void MainWindow::on_pushButton_4_clicked()//save changes //THE WORKING FUNCTION//SHOULD DELETE IT SOON
{//only one piece of text can be tagged with <i> or <b> tags... it's strange
    //no, it's not. It saves all the tags first time. But the second time
    //tags aren't there anymore... and it saves just the text, not recognizing
    //that it was italic or bold
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
    ui->textEdit->setText("");
    // ui->tableView_3->hideColumn(1);
}
void MainWindow::slot1DeleteARecord(){
    on_pushButton_5_clicked();
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_7_clicked()
{
    QString str = ui->textEdit->toPlainText();
    QString str2 = ui->textEdit_2->toPlainText();
    //ui->textEdit->to
    ded = new dayEditDialog(str, str2);
    ded->changedRecord = currRecId;//inserted the needed ID to change from a new ded dialog window
    // ded->anOldText = ui->textEdit->toPlainText();//inserted current text to edit//
    //it works, but the constructor can't build the string IN TIME(вовремя) to pass it to it's textEdit
    ded->show();
}

//search implementation
//    QStandardItemModel*  model = new QStandardItemModel ();

//    ui->tableView_2->setModel(model);
//    for (int index = 0; index < model->columnCount(); index++)
//    {
//        QList<QStandardItem*> foundLst = model->findItems("12", Qt::MatchExactly, index);
//        int count = foundLst.count();
//        if(count>0)
//        {
//            for(int k=0; k<count; k++)
//            {
//                QModelIndex modelIndex = model->indexFromItem(foundLst[k]);
//                qDebug()<< "column= " << index << "row=" << modelIndex.row();
//                ((QStandardItemModel*)modelIndex.model())->item(modelIndex.row(),index)->setData(QBrush(Qt::green),Qt::BackgroundRole);
//            }
//        }
//    }
