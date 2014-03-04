#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT       += core gui widgets quick

TARGET = TEG
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    mapa.cpp \
    continente.cpp \
    pais.cpp \
    jugador.cpp \
    objetivo.cpp \
    utiles.cpp

HEADERS  += mainwindow.h \
    game.h \
    mapa.h \
    continente.h \
    pais.h \
    jugador.h \
    objetivo.h \
    utiles.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    styles.qss
