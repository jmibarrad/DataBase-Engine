#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T07:31:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entries.cpp \
    device.cpp \
    addregistry.cpp

HEADERS  += mainwindow.h \
    entries.h \
    device.h \
    addregistry.h

FORMS    += mainwindow.ui \
    addregistry.ui

RESOURCES += \
    resource.qrc
