#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT       += core gui widgets quick

TARGET = TEG
TEMPLATE = app

SOURCES += continente.cpp \
    game.cpp \
    inteligenciaartificial.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    objetivo.cpp \
    pais.cpp \
    rondamanager.cpp \
    utiles.cpp \
    turnos/turno.cpp \
    turnos/turnoataques.cpp \
    turnos/turnofichas.cpp \
    heuristicas/heuristica.cpp \
    heuristicas/heuristicaataque.cpp \
    heuristicas/heuristicadefensa.cpp \
    heuristicas/heuristicamix.cpp \
    acciones/accion.cpp \
    acciones/accionataque.cpp \
    acciones/accionreagrupe.cpp

HEADERS  += continente.h \
    game.h \
    inteligenciaartificial.h \
    jugador.h \
    mainwindow.h \
    mapa.h \
    objetivo.h \
    pais.h \
    rondamanager.h \
    utiles.h \
    turnos/turno.h \
    turnos/turnoataques.h \
    turnos/turnofichas.h \
    heuristicas/heuristica.h \
    heuristicas/heuristicaataque.h \
    heuristicas/heuristicadefensa.h \
    heuristicas/heuristicamix.h \
    acciones/accion.h \
    acciones/accionataque.h \
    acciones/accionreagrupe.h


FORMS    += mainwindow.ui

OTHER_FILES +=

SUBDIRS += teg.pro
