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
    utiles.cpp \
    turno.cpp \
    turnofichas.cpp \
    turnoataques.cpp \
    rondamanager.cpp \
    inteligenciaartificial.cpp \
    heuristicas/heuristicaataque.cpp \
    heuristicas/heuristica.cpp \
    heuristicas/heuristicadefensa.cpp \
    heuristicas/heuristicamix.cpp

HEADERS  += mainwindow.h \
    game.h \
    mapa.h \
    continente.h \
    pais.h \
    jugador.h \
    objetivo.h \
    utiles.h \
    turno.h \
    turnofichas.h \
    turnoataques.h \
    rondamanager.h \
    inteligenciaartificial.h \
    heuristicas/heuristicaataque.h \
    heuristicas/heuristica.h \
    heuristicas/heuristicadefensa.h \
    heuristicas/heuristicamix.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    styles.qss
