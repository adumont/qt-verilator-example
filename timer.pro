#-------------------------------------------------
#
# Project created by QtCreator 2019-01-13T15:09:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = timer
TEMPLATE = app


INCLUDEPATH += obj_dir
INCLUDEPATH += /home/adumont/toolchain/share/verilator/include

CONFIG += c++11

LIBS += ../timer/obj_dir/*.o

SOURCES += main.cpp\
        mainwindow.cpp \
    mled.cpp

HEADERS  += mainwindow.h \
    mled.h

FORMS    += mainwindow.ui

RESOURCES += \
    assets.qrc
