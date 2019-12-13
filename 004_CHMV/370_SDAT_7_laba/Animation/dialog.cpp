#include "dialog.h"
#include "ui_dialog.h"
#include"myitem.h"
#include "mouse.h"
#include "dot.h"
#include"mouse3.h"
#include"sofa.h"
#include "mysquare.h"
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{


    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(50,50,550,550);
    QPen mypen = QPen(Qt::red);

    //pixmap_item = QtWidgets.QGraphicsPixmapItem(QtGui.QPixmap("path/of/image"))
  //  self.scene.addItem(pixmap_item)
           QPixmap *ss = new QPixmap();

           QLabel *ql = new QLabel();
           //ql->setPixmap(pix);

           item = new QGraphicsPixmapItem(QPixmap("C:/Users/Stepan/source/repos/370_SDAT_7_laba/Animation/pillow.jpg"));//C:\Users\Stepan\source\repos\370_SDAT_7_laba\Animation
           item->setPos(150, 150);// item->setPos(250, 250);
           item->setFlag(QGraphicsItem::ItemIsMovable);

           scene->addItem(item);


    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine, mypen);
    scene->addLine(LeftLine, mypen);
    scene->addLine(RightLine, mypen);
    scene->addLine(BottomLine, mypen);

    int ItemCount = 1;//число движущихся объектов
    for(int i  =0; i<ItemCount;i++){
        //MyItem *item = new MyItem(i);
       // scene-> addItem(item);
    }
    int MiceCount = 1;//число мышей
    for(int i  =0; i<MiceCount;i++){
        Mouse *mouse = new Mouse(i);
      //  mouse3 *ms = new mouse3();
        scene-> addItem(mouse);
      //  scene->addItem(ms);
    }
    Dot *dit = new Dot();
   // scene->addItem(dit);

    //QPixmap pix("C:/Users/Stepan/source/repos/370/Animation/pillow.jpg");
   // scene->addPixmap(pix);//просто добавляет рисунок в левый верхний угол

    square = new MySquare();
    scene->addItem(square);
    square2 = new MySquare();
    //square2->paint(pix);
    scene->addItem(square2);
    //scene->addItem(label);
   // labelp->event()
  //  ui->labelp->setPixmap(pix);

    //sofa *so = new sofa();
  //  scene->addItem(so);


    timer = new QTimer(this);//каждый раз, как таймер срабатывает, он говорит слоту advance на сцене.
    //Сцена оповещает все объекты на сцене об этом
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));//advance говорит всем объектам продвинуться на 1 шаг
    timer->start(100);//milliseconds




}

Dialog::~Dialog()
{
    delete ui;
}

