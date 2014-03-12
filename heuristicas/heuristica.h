#ifndef HEURISTICA_H
#define HEURISTICA_H

#include "../turnos/turno.h"
#include "../turnos/turnoataques.h"
#include "../turnos/turnofichas.h"

#include "../acciones/accion.h"
#include "../acciones/accionataque.h"
#include "../acciones/accionreagrupe.h"

namespace TEG{
    class Heuristica;
 }
class TEG::Heuristica
{
public:
    Heuristica();
    virtual ~Heuristica();

    void fichas(TEG::TurnoFichas *turno);
    void ataque(TEG::TurnoAtaques *turno);
    void reagrupe(TEG::TurnoAtaques *turno);

    virtual float factorReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    virtual float cantidadReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    virtual float factorAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    virtual float cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    virtual int factorFichas(TEG::TurnoFichas *turno, TEG::Pais *pais);

    virtual int next(TEG::TurnoAtaques *turno, Pais *pais);
protected:
    QList<TEG::Accion*> *getAcciones(TEG::TurnoAtaques *turno, bool reagrupe );

    static bool sortingAccion(const QPair<TEG::Accion*,int>& e1, const QPair<TEG::Accion*,int>& e2);
};

#endif // HEURISTICA_H
