/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableView *tableView_2;
    QTableView *tableView_3;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton_6;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(928, 624);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/Common/iconsmall_zWo_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 110, 211, 21));
        pushButton->setToolTipDuration(4);
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(20, 140, 201, 361));
        tableView_2->setBaseSize(QSize(0, 0));
        tableView_2->setToolTipDuration(10);
        tableView_2->setAlternatingRowColors(true);
        tableView_2->setSortingEnabled(true);
        tableView_2->horizontalHeader()->setVisible(false);
        tableView_2->verticalHeader()->setVisible(false);
        tableView_2->verticalHeader()->setDefaultSectionSize(30);
        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(20, 0, 621, 26));
        tableView_3->setToolTipDuration(5);
        tableView_3->horizontalHeader()->setVisible(false);
        tableView_3->verticalHeader()->setVisible(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 211, 21));
        pushButton_2->setToolTipDuration(5);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(280, 80, 621, 421));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(700, 510, 201, 21));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 510, 211, 21));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 131, 22));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 510, 80, 21));
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(370, 510, 191, 22));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(569, 510, 101, 21));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(280, 40, 621, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 928, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action_2);
        menu_2->addAction(action);

        retranslateUi(MainWindow);
        QObject::connect(action_2, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(action, SIGNAL(triggered()), MainWindow, SLOT(slot1Help()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DailyPlaner", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\275\320\260\320\262\320\270\320\263\320\260\321\202\320\276\321\200 \320\277\320\276\320\274\320\276\321\211\320\270", nullptr));
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        action_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214 \320\262 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
#ifndef QT_NO_TOOLTIP
        tableView_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\267\320\264\320\265\321\201\321\214 \320\274\320\276\320\266\320\275\320\276 \320\276\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \320\267\320\260\320\277\320\270\321\201\320\270 \320\264\320\262\320\276\320\271\320\275\321\213\320\274 \320\272\320\273\320\270\320\272\320\276\320\274</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tableView_3->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>\320\227\320\264\320\265\321\201\321\214 \320\274\320\276\320\266\320\275\320\276 \320\276\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272 \320\267\320\260\320\277\320\270\321\201\320\270 \320\264\320\262\320\276\320\271\320\275\321\213\320\274 \320\272\320\273\320\270\320\272\320\276\320\274</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\275\320\260\320\266\320\260\321\202\321\214, \320\265\321\201\320\273\320\270 \320\267\320\260\320\277\320\270\321\201\320\270 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\216\321\202\321\201\321\217 \320\275\320\265\320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\320\276</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271 \320\276\321\202\320\272\321\200\321\213\321\202\320\276\320\271 \320\267\320\260\320\277\320\270\321\201\320\270</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\273\320\265\320\262\321\213\320\274 \320\272\320\273\320\270\320\272\320\276\320\274 \320\274\321\213\321\210\320\270 \320\267\320\260\320\277\320\270\321\201\320\270 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 \320\262\321\213\321\210\320\265</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\262\321\213\320\261\320\276\321\200 \321\201\321\202\320\270\320\273\321\217</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\250\321\200\320\270\321\204\321\202", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\267\320\260\321\207\320\265\321\200\320\272\320\275\321\203\321\202\321\213\320\271", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\274\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\277\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
