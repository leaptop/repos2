#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include<QTableView>
#include "styleloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      //   HelpBrowser helpBrowser(":/htmFiles/Common", "index.htm");//helping window activation
//         helpBrowser.resize(450, 350);
//         helpBrowser.show();
   // QObject::connect(&dd, SIGNAL(on_buttonBox_accepted()),//doesn't work for some reason
             //         SLOT(reloadTable()));

//StyleLoader::attach();//uncommenting it allows to change style momentarily by pressing F5
    //at the same time input in textEdit etc fileds becomes impossible

      QFile file(":/styles/Common/style.qss");//this is how to use resource files
      qDebug()<<QFile::exists("./../../CW01/style.qss");//still learning how to search files
     // qDebug()<<QFile::exists("./qu.txt");//RETURNS TRUE IF THE FILE IS IN SOURCE DIRECTORY
        file.open(QFile::ReadOnly);
        QString strCSS = QLatin1String(file.readAll());
        qApp->setStyleSheet(strCSS);

    MainWindow w;
 //   DateDialog dd;
   // dd.setParent(&w);//it adds the contents of dd
    //straight into MainWindow w!!! Funny looking picture

    w.show();
    return a.exec();
}
