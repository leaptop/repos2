#include <QApplication>
#include <QtQml/QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine(QUrl("qrc:///main.qml"));
    return app.exec();
}
