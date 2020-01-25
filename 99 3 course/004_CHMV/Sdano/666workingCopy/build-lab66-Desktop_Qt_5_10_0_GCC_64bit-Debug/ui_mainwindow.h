/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_photo;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_load;
    QGridLayout *gridLayout_2;
    QLabel *label_birthday;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_m;
    QRadioButton *radioButton_f;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_phone;
    QLabel *label_phone;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_dolzhnost;
    QLineEdit *lineEdit_fio;
    QLabel *label_dolzhnost;
    QLabel *label_fio;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(614, 468);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(64, 21, 450, 259));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_photo = new QLabel(layoutWidget);
        label_photo->setObjectName(QStringLiteral("label_photo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_photo->sizePolicy().hasHeightForWidth());
        label_photo->setSizePolicy(sizePolicy);
        label_photo->setMinimumSize(QSize(200, 200));
        label_photo->setStyleSheet(QLatin1String("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));
        label_photo->setFrameShape(QFrame::Box);
        label_photo->setFrameShadow(QFrame::Sunken);
        label_photo->setLineWidth(4);
        label_photo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_photo);

        lineEdit_path = new QLineEdit(layoutWidget);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));

        verticalLayout->addWidget(lineEdit_path);

        pushButton_load = new QPushButton(layoutWidget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setStyleSheet(QStringLiteral("background:rgb(133, 192, 255)"));

        verticalLayout->addWidget(pushButton_load);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_birthday = new QLabel(layoutWidget);
        label_birthday->setObjectName(QStringLiteral("label_birthday"));
        label_birthday->setStyleSheet(QLatin1String("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout_2->addWidget(label_birthday, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_m = new QRadioButton(layoutWidget);
        radioButton_m->setObjectName(QStringLiteral("radioButton_m"));
        radioButton_m->setStyleSheet(QStringLiteral("font: 10pt \"xos4 Terminus\";"));

        horizontalLayout->addWidget(radioButton_m);

        radioButton_f = new QRadioButton(layoutWidget);
        radioButton_f->setObjectName(QStringLiteral("radioButton_f"));
        radioButton_f->setStyleSheet(QStringLiteral("font: 10pt \"xos4 Terminus\";"));

        horizontalLayout->addWidget(radioButton_f);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 2);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(dateEdit, 0, 1, 1, 1);

        lineEdit_phone = new QLineEdit(layoutWidget);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));
        lineEdit_phone->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(lineEdit_phone, 1, 1, 1, 1);

        label_phone = new QLabel(layoutWidget);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setStyleSheet(QLatin1String("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout_2->addWidget(label_phone, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        lineEdit_dolzhnost = new QLineEdit(layoutWidget);
        lineEdit_dolzhnost->setObjectName(QStringLiteral("lineEdit_dolzhnost"));

        gridLayout->addWidget(lineEdit_dolzhnost, 1, 1, 1, 1);

        lineEdit_fio = new QLineEdit(layoutWidget);
        lineEdit_fio->setObjectName(QStringLiteral("lineEdit_fio"));

        gridLayout->addWidget(lineEdit_fio, 0, 1, 1, 1);

        label_dolzhnost = new QLabel(layoutWidget);
        label_dolzhnost->setObjectName(QStringLiteral("label_dolzhnost"));
        label_dolzhnost->setStyleSheet(QLatin1String("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout->addWidget(label_dolzhnost, 1, 0, 1, 1);

        label_fio = new QLabel(layoutWidget);
        label_fio->setObjectName(QStringLiteral("label_fio"));
        label_fio->setStyleSheet(QLatin1String("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout->addWidget(label_fio, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 400, 75, 23));
        pushButton->setStyleSheet(QStringLiteral("background:rgb(176, 255, 185)"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_photo->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276", nullptr));
        pushButton_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_birthday->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        radioButton_m->setText(QApplication::translate("MainWindow", "\320\234", nullptr));
        radioButton_f->setText(QApplication::translate("MainWindow", "\320\226", nullptr));
        label_phone->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        lineEdit_fio->setText(QString());
        label_dolzhnost->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_fio->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
