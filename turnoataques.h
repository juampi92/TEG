#ifndef TURNOATAQUES_H
#define TURNOATAQUES_H

#include "turno.h"

namespace TEG{
    class TurnoAtaques;
}

class TEG::TurnoAtaques : public TEG::Turno
{
public:
    TurnoAtaques(TEG::RondaManager *ronda, TEG::Jugador *plyr);
    ~TurnoAtaques();


private:
    void startTurno();
};

#endif // TURNOATAQUES_H
