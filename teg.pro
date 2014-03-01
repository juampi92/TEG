#-------------------------------------------------
#
# Project created by QtCreator 2014-02-25T20:32:56
#
#-------------------------------------------------

QT       += core gui widgets quick

TARGET = teg
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    mapa.cpp \
    continente.cpp \
    pais.cpp

HEADERS  += mainwindow.h \
    game.h \
    mapa.h \
    continente.h \
    pais.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    styles.qss
