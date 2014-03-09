#ifndef ACCIONREAGRUPE_H
#define ACCIONREAGRUPE_H

#include "accion.h"
#include "turnos/turno.h"

namespace TEG{
    class AccionReagrupe;
}

class TEG::AccionReagrupe : public TEG::Accion
{
public:
    AccionReagrupe(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game, TEG::Turno *turno);
    ~AccionReagrupe();

    bool validar();
    void execute();

    int getMax();
private:
    TEG::Turno *turno;
};

#endif // ACCIONREAGRUPE_H
