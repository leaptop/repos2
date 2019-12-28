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

//    if(file.open(QIODevice::Append)){         //will write to the end
//        QTextStream stream (&file);
//        QString str = "\na new line";
//        stream<<str.toUpper();
//        if(stream.status()!=QTextStream::Ok){
//            qDebug()<<"Ошибка чтения файла";
//        }
//        file.close();
//    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

