#ifndef RONDAMANAGER_H
#define RONDAMANAGER_H

#include "game.h"
#include "jugador.h"
#include "turnos/turno.h"

namespace TEG{
    class RondaManager;
    class Turno;
    class Jugador;
    class Game;
}

class TEG::RondaManager
{
public:
    RondaManager(TEG::Game *juego, QList<TEG::Jugador*> *players);
    ~RondaManager();

    void start();
    void end(bool winner=false);
    void nextTurno();
    void nextRonda();
    void playTurno();
    QString showObjetivo() const;
    void setType(int t);

    void btnClick(int id);
    void btnNext();

    TEG::Game *game;
    TEG::Turno *turno;
private:
    int type;
    int special;
    QList<TEG::Jugador*> *players;
    QList<TEG::Jugador*>::iterator actual;
    QList<TEG::Jugador*>::iterator inicio;

    void desplazarOrden();
};

#endif // RONDAMANAGER_H
