#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alexeev.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    alexeev *myform;
signals:
    void sendData(QString str);

private slots:
    void onButtonSend();
    void on_pushButton_load_clicked();
    void on_pushButton_clicked();
    void on_pushButton_clicked(bool checked);
    void on_pushButton_toggled(bool checked);
    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_destroyed();
};

#endif // MAINWINDOW_H
