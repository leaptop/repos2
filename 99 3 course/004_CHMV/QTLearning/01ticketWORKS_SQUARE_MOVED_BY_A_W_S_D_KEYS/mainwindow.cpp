#include "mainwindow.h"
#include "ui_mainwindow.h"

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(640,640);
    this->setFixedSize(640,640);

    scene = new QGraphicsScene(this);   // Init graphics scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(600,600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(0,0,500,500);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    item = new moveitem();
    item->setPos(randomBetween(30, 470),
                 randomBetween(30,470));
    scene->addItem(item);
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W){
        //item->setPos(item->y() +5,item->x());
        item->setY(item->y() -5);
    }else if(event->key()==Qt::Key_A){
        item->setX(item->x()-5);
    }if(event->key()==Qt::Key_S){
        item->setY(item->y() +5);
    }else if(event->key()==Qt::Key_D){
        item->setX(item->x()+5);
    }

}
void MainWindow::keyReleaseEvent(QKeyEvent *event){

}


