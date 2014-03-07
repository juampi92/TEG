#ifndef JUGADOR_H
#define JUGADOR_H

#include <QString>
#include "pais.h"
#include "objetivo.h"
#include "game.h"
#include "turno.h"

namespace TEG{
    class Jugador;
    class Game;
    class Turno;
}

class TEG::Jugador
{
public:
    Jugador(TEG::Game *game, QString nom, int id, QString color);
    ~Jugador();

    int getID();
    QString getColor();
    QString getName();
    QList<TEG::Pais*> *getListPaises();
    int getCantPaises();
    int getCantEjercitos();

    void setObjetivo(TEG::Objetivo *obj);
    QString showObjetivo() const;
    void addPais(TEG::Pais *pais);
    void removePais(TEG::Pais *pais);

    void playFichas(TEG::Turno *turno);
    void playAtaque(TEG::Turno *turno);

protected:
    TEG::Game *game;
    QString nom;
    int id;
    QString color;
    TEG::Objetivo *objetivo;
    QList<TEG::Pais*> *paises;
};

#endif // JUGADOR_H
