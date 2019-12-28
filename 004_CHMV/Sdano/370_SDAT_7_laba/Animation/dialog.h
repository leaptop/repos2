#ifndef DIALOG_H
#define DIALOG_H

#include"mysquare.h"
#include<QDialog>
#include<QtCore>
#include<QtGui>
#include <QGraphicsScene>
#include<QtWidgets>
#include<QGraphicsPixmapItem>
#include<QLabel>

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
    MySquare *square;
    MySquare *square2;
  QGraphicsPixmapItem  *pixmap_item;
  QPixmap *ss;
  QLabel *ql;
  QLabel *labelp;
   QGraphicsPixmapItem *item;

};
#endif // DIALOG_H
