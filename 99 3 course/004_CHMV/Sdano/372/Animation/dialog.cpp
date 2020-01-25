#include "dialog.h"
#include "ui_dialog.h"
#include"myitem.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300);
    QPen mypen = QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine, mypen);
    scene->addLine(LeftLine, mypen);
    scene->addLine(RightLine, mypen);
    scene->addLine(BottomLine, mypen);

    int ItemCount = 30;//число движущихся объектов
    for(int i  =0; i<ItemCount;i++){
        MyItem *item = new MyItem();
        scene-> addItem(item);
    }

    timer = new QTimer(this);//каждый раз, как таймер срабатывает, он говорит слоту advance на сцене.
    //Сцена оповещает все объекты на сцене об этом
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));//advance говорит всем объектам продвинуться на 1 шаг
    timer->start(100);//milliseconds


}

Dialog::~Dialog()
{
    delete ui;
}

