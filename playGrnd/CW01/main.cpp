#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include<QTableView>
#include "StyleLoader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      //   HelpBrowser helpBrowser(":/htmFiles/Common", "index.htm");//helping window activation
//         helpBrowser.resize(450, 350);
//         helpBrowser.show();

//  QFile file("./darkstyle/darkstyle.qss");
//  qDebug()<<QFile::exists("./darkstyle/darkstyle.qss");
//  qDebug()<<QFile::exists("./qu.txt");
//    file.open(QFile::ReadOnly);
//    QString strCSS = QLatin1String(file.readAll());
//    qApp->setStyleSheet(strCSS);
    StyleLoader::attach();//this one gets style.qss from build/debug
    //qApp->setStyleSheet("MainWindow::hover {background-color:blue}");

    MainWindow w;
   // a.setStyleSheet(strCSS);
 //   DateDialog dd;
   // dd.setParent(&w);//it adds the contents of dd
    //straight into MainWindow w!!! Funny looking picture

    w.show();
    return a.exec();
}
