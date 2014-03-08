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
    virtual ~Turno();

    virtual int getFichasDisp();
    virtual void play();
    virtual bool next();

    virtual void paisClick(int id);
    virtual void btnAttack();

    void end();

    TEG::Jugador *player;
protected:
    virtual void startTurno();

    TEG::RondaManager *ronda;
};

#endif // TURNO_H
