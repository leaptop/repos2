
#include <QApplication>
#include "startdialog_Alexeev.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startdialog_alexeev startDialog;
    startDialog.show();
    return a.exec();
}
