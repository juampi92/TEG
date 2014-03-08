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

    void play();
    bool next();
    void paisClick(int id);

    void btnAttack();
private:

    void startTurno();
    void selectOrigen(int id, bool friends);
    void selectDestino(int id);

    bool reagrupe;
    TEG::Pais* origen;
    TEG::Pais* destino;

};

#endif // TURNOATAQUES_H
