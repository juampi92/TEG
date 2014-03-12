#ifndef TURNOATAQUES_H
#define TURNOATAQUES_H

#include "turno.h"
#include "../acciones/accion.h"
#include "../acciones/accionataque.h"
#include "../acciones/accionreagrupe.h"

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

    void endDadosAnimacion();

    void setAccion(TEG::Accion * accion);
private:

    void startTurno();
    void selectOrigen(int id, bool friends);
    void selectDestino(int id);

    bool reagrupe;
    TEG::Pais* origen;
    TEG::Pais* destino;


    TEG::Accion *currentAction;
    QList<TEG::AccionAtaque*> *ataques;
    QList<TEG::AccionReagrupe*> *reagrupes;

};

#endif // TURNOATAQUES_H
