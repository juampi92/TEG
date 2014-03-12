#ifndef JUGADOR_H
#define JUGADOR_H

#include <QString>
#include "pais.h"
#include "objetivo.h"
#include "game.h"
#include "turnos/turno.h"
#include "acciones/accion.h"

namespace TEG{
    class Jugador;
    class Game;
    class Turno;
    class Accion;
}

class TEG::Jugador
{
public:
    Jugador(TEG::Game *game, QString nom, int id, QString color);
    ~Jugador();

    int getID();
    virtual int getIA();
    QString getColor();
    QString getName();

    QList<TEG::Pais*> *getPaises();
    QList<TEG::Pais*> *getListPaises(bool hasFichas = false);
    int getCantPaises();
    int getCantEjercitos();
    QList<TEG::Pais*> *getLimitrofes(int id, bool friends);

    void setObjetivo(TEG::Objetivo *obj);
    QString showObjetivo() const;
    int * getContArray();
    bool gano();

    void addPais(TEG::Pais *pais);
    void removePais(TEG::Pais *pais);

    virtual void playFichas(TEG::Turno *turno);
    virtual void playAtaque(TEG::Turno *turno);
    virtual void playReagrupe(TEG::Turno * turno);
    virtual int playReagrupeCant(TEG::Turno * turno, TEG::Accion *acc);
    virtual int playConquistaCant(TEG::Turno * turno, TEG::Accion *acc);

    TEG::Objetivo *objetivo;
protected:
    TEG::Game *game;
    QString nom;
    int id;
    QString color;
    QList<TEG::Pais*> *paises;
    int * conts;
};

#endif // JUGADOR_H
