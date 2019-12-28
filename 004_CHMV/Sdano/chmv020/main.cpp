#include "mainwindow.h"
#include "StartDialog_Alexeev.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
  //  w.show();
    StartDialog_Alexeev startDialog;
    startDialog.show();
    return a.exec();
}
