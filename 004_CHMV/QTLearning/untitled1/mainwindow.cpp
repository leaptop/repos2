#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    QList<int> list;                 //about QList
    //    list<<10<<20<<30;
    ////    for (int i = 0;i<list.length();i++) {
    ////        qDebug()<<"Element: "<<list[i];
    ////    }
    //    int i = 0;
    //    while(!list.empty()){
    //        qDebug()<<"Element: "<<list[i++];
    //    }

    //qDebug()<<"QDir::current() gives: "<< QDir::current() ;//shows the current folder(for .o, .exe files)

    //apparently it's assumed that editing of the text should happen somewhere else...
    //it's just I can't understand how to write text to an end of the txt file(needed to use Append)
    //    QFile file ("file.txt");                      //about work with text files. Reading
    //    if(file.open(QIODevice::ReadOnly)){
    //        QTextStream stream (&file);
    //        QString str;
    //        while(!stream.atEnd()){
    //            str = stream.readLine();
    //            qDebug()<<str;
    //        }
    //        if(stream.status()!=QTextStream::Ok){
    //            qDebug()<<"Ошибка чтения файла";
    //        }

    //        file.close();
    //    }
    //    if(file.open(QIODevice::ReadWrite)){      //will write to the first line
    //        QTextStream stream (&file);
    //        QString str = "a new line";
    //        stream<<str.toUpper();
    //        if(stream.status()!=QTextStream::Ok){
    //            qDebug()<<"Ошибка чтения файла";
    //        }
    //        file.close();
    //    }

//        if(file.open(QIODevice::Append)){         //will write to the end
//            QTextStream stream (&file);
//            QString str = "\na new line";
//            stream<<str.toUpper();
//            if(stream.status()!=QTextStream::Ok){
//                qDebug()<<"Ошибка чтения файла";
//            }
//            file.close();
//        }

    //QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
      //                                                "/home",
      //                                                QFileDialog::ShowDirsOnly
      //                                                | QFileDialog::DontResolveSymlinks);
    //QString str = QFileDialog::getExistingDirectory(0, "Open Dialog", "");
    //QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.cpp *.h");
    ////str will contain a full path to a file

    //    QPrinter *printer;                //shows a printer's dialog
    //    QPrintDialog* pPrintDialog = new QPrintDialog(printer);
    //    if (pPrintDialog->exec() == QDialog::Accepted) {
    //        // Печать
    //    }
    //    delete pPrintDialog;


    //    QColor color = QColorDialog::getColor();                //color choice
    //    if(!color.isValid()){
    //        //cancel
    //    }


    //bool bOK;                     //Font choice
    //QFont fnt = QFontDialog::getFont(&bOK);
    //if(!bOK){
    //    //the cancel button was pressed
    //}


    //    bool bOK;                     //input dialog
    //    QString str = QInputDialog::getText(0, "Input", "Name:", QLineEdit::Normal,
    //                                        "Smth already inserted", &bOK);

//    int n = 100000;
//    QProgressDialog* pprd = new QProgressDialog("Processing the data...", "&Cancel", 0, n);
//    pprd->setMinimumDuration(0);//задержка показа диалогового окна. Как она работает хз
//    pprd->setWindowTitle("Please Wait");
//    for (int i = 0;i<n;++i) {
//        pprd->setValue(i);
//        qApp->processEvents();
//        if(pprd->wasCanceled()){
//            break;
//        }
//    }
//    pprd->setValue(n);
//    delete pprd;


//     QMessageBox::information(0, "Information", "Operation Complete");//informational

//    ////a warning message with options: yes or no
//    int n = QMessageBox::warning(0, "Warning", "The text in the file has changed"
//                                               "\n Do you want to save the changes?",
//                                 QMessageBox::Yes | QMessageBox::No,
//                                 QMessageBox::Yes);
//    if(n==QMessageBox::Yes){
//        //Saving the changes
//    }


// (new QErrorMessage(this))->showMessage("Write Error");//obviously error message


//   QPushButton* pcmd = new QPushButton("&Ok");//tooltip(всплывающая подсказка)
//   pcmd->setToolTip("Button");
//   pcmd->show();


//helpbrowser is launched by invoking from main.cpp






}

MainWindow::~MainWindow()
{
    delete ui;
}

