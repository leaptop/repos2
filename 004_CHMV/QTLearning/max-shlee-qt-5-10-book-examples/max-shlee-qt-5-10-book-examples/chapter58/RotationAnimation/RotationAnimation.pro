TEMPLATE = app

QT += quick qml
SOURCES += main.cpp \
    mainwindow.cpp
RESOURCES += qml.qrc 

windows:TARGET	= ../RotationAnimation

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h