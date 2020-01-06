#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include <QTableView>
#include "styleloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //StyleLoader::attach();//uncommenting it allows to change style momentarily by pressing F5
    //at the same time input in textEdit etc fileds becomes impossible
    //style.qss is in build/debug

    QFile file(":/styles/Common/style.qss");//this is how to use resource files
    qDebug()<<QFile::exists("./../../CW01/style.qss");//still learning how to search files
    // qDebug()<<QFile::exists("./qu.txt");//RETURNS TRUE IF THE FILE IS IN SOURCE DIRECTORY
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());
    qApp->setStyleSheet(strCSS);

    MainWindow w;
    w.show();
    return a.exec();
}
