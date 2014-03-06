#ifndef TURNO_H
#define TURNO_H

#include "rondamanager.h"
#include "jugador.h"

namespace TEG{
    class Turno;
    class RondaManager;
    class Jugador;
}

class TEG::Turno
{
public:
    Turno(TEG::RondaManager *ronda, TEG::Jugador *plyr);
    ~Turno();

    virtual int getFichasDisp();
    virtual void play();

    virtual void paisClick(int id);

    void end();

protected:
    virtual void startTurno();

    TEG::RondaManager *ronda;
    TEG::Jugador *player;
};

#endif // TURNO_H
