#ifndef RONDAMANAGER_H
#define RONDAMANAGER_H

#include "game.h"
#include "turno.h"

namespace TEG{
    class RondaManager;
    class Turno;
}

class TEG::RondaManager
{
public:
    RondaManager(TEG::Game *juego, QList<TEG::Jugador*> *players);
    ~RondaManager();

    void start();
    void end();
    void nextTurno();
    void playTurno();

    void setType(int t);

    void btnClick(int id);

    TEG::Game *game;
private:
    int type;
    QList<TEG::Jugador*>::iterator begin;
    QList<TEG::Jugador*>::iterator actual;

    TEG::Turno *turno;
};

#endif // RONDAMANAGER_H
