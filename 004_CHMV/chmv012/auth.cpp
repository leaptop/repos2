#include "auth.h"
#include "ui_auth.h"
//#include <QPixmap>

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Stepan/source/repos/chmv012/01.png");
    ui->label_pic->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
}

auth::~auth()
{
    delete ui;
}

void auth::on_label_linkActivated(const QString &link)
{

}
