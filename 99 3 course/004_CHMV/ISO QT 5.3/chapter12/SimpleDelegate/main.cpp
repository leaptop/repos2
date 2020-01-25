// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtWidgets>

// ======================================================================
class SimpleDelegate : public QStyledItemDelegate {
public:
    SimpleDelegate(QObject* pobj = 0) : QStyledItemDelegate(pobj) 
    {
    }
    
    void paint(QPainter*                   pPainter,
               const QStyleOptionViewItem& option,
               const QModelIndex&          index
              ) const
    {
        if (option.state & QStyle::State_MouseOver) {
            QRect           rect = option.rect;
            QLinearGradient gradient(0, 0, rect.width(), rect.height());

            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter, option, index);
    }
};

// ----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "Item3");

    QListView listView;
    listView.setModel(&model);
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);
    listView.show();

    return app.exec();
}
