#ifndef DIALOG_H
#define DIALOG_H


#include<QDialog>
#include<QtCore>
#include<QtGui>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;//это часть вида
    QTimer *timer;//это таймер

};
#endif // DIALOG_H
