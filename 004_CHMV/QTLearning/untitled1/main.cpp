#include "mainwindow.h"

#include <QApplication>
#include "helpbrowser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//     HelpBrowser helpBrowser(":/", "index.htm");//helping window activation
//     helpBrowser.resize(450, 350);
//     helpBrowser.show();


            QStringList lst;  //learned about the qrc file and how to configure it
            QListWidget lwg;//-trying to turn pictures on... again page 176-
            QListWidgetItem* pitem = nullptr;
           // lwg.setIconSize(QSize(48,36));
            lst<<"Linux"<<"Windows"<<"MacOSX"<<"Android";

            foreach(QString str, lst){
                QIcon *ico = new QIcon(str + "logo.jpg");
                pitem = new QListWidgetItem( str, &lwg);
                //pitem->setIcon(*ico);
                //pitem->setIcon(QPixmap(":/" + str + "logo.jpg"));//-doesn't work for some reason-
                //pitem->setIcon(QIcon(QPixmap(":/" + str + "logo.jpg")));
            }
            lwg.resize(500, 500);
            lwg.show();


        QStringList lst;        //-pictograms regime... doesn't work-
        QListWidget lwg;
        QListWidgetItem* pitem = nullptr;

        lwg.setIconSize(QSize(48, 48));
        lwg.setSelectionMode(QAbstractItemView::MultiSelection);
        lwg.setViewMode(QListView::IconMode);
        lst<<"Linux"<<"Windows"<<"MacOSX"<<"Android";
        foreach(QString str, lst){
            pitem = new QListWidgetItem(str, &lwg);
            pitem->setIcon(QPixmap(":/" + str + ".jpg"));//concatenates the thingies to get the
            pitem->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable |//pics from the "/" prefix
                            Qt::ItemIsEditable | Qt::ItemIsDragEnabled);
        }
        lwg.resize(150, 150);
        lwg.show();





    MainWindow w;

    // w.show();
    return a.exec();
}
