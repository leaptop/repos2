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
        psplash->showMessage("Loading modules: " +QString::number(i)+"%",
                             Qt::AlignCenter|Qt::AlignCenter, Qt::black);
        qApp->processEvents();
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //StyleLoader::attach();//uncomment to apply changes from a qss file momentarily(F5)
    //at the same time input in textEdit etc fileds becomes impossible
    //style.qss is in build/debug

    // qDebug()<<QFile::exists("./qu.txt");//RETURNS TRUE IF THE FILE IS IN SOURCE DIRECTORY
    QFile file(":/styles/Common/style.qss");//this is how to use resource files
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());
    //qApp->setStyleSheet(strCSS);//uncomment to apply changes from a qss file

    //    QSplashScreen splash(QPixmap(":/pics/Common/s.png"));//uncomment to turn zastavka on
    //    splash.show();
    //    loadModules(&splash);

    MainWindow w;
    //  splash.finish(&w);//uncomment to turn zastavka on

    w.show();
    return a.exec();
}
