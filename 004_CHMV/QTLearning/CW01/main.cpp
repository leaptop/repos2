#include "mainwindow.h"
#include "datedialog.h"
#include <QApplication>
#include <QtSql>
#include <QTableView>
#include "styleloader.h"
void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();
    for(int i = 0; i <100; ){
        if(time.elapsed()>40){
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: "
                             +QString::number(i)+"%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::black
                             );
        qApp->processEvents();
    }
}
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
    //qApp->setStyleSheet(strCSS);

//    QSplashScreen splash(QPixmap(":/pics/Common/s.png"));
//    splash.show();
//    loadModules(&splash);

    MainWindow w;
  //  splash.finish(&w);

    w.show();
    return a.exec();
}
