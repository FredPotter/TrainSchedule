#-------------------------------------------------
#
# Project created by QtCreator 2022-10-29T23:42:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainSchedule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addnew.cpp \
    searchwindow.cpp

HEADERS  += mainwindow.h \
    addnew.h \
    searchwindow.h \
    train.h

FORMS    += mainwindow.ui \
    addnew.ui \
    searchwindow.ui

RESOURCES += \
    resources.qrc
