#include "auth.h"
#include "ui_auth.h"

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Stepan/source/repos/chmv012/01.png");
   ui->label_pic->setPixmap(pix);
}

auth::~auth()
{
    delete ui;
}
