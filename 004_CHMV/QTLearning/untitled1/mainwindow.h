#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextStream>
#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QProgressDialog>
#include <QMessageBox>
#include <QErrorMessage>
#include <QFontDialog>
#include <QFontDialog>
#include <QFontDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
