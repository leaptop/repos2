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
StyleLoader::attach();

    MainWindow w;
 //   DateDialog dd;
   // dd.setParent(&w);//it adds the contents of dd
    //straight into MainWindow w!!! Funny looking picture

    w.show();
    return a.exec();
}
