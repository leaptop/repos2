#include "calendardialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalendarDialog w;
    w.show();
    return a.exec();
}
