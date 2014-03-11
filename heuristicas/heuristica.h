#ifndef HEURISTICA_H
#define HEURISTICA_H

#include "../turnos/turno.h"

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

    void fichas(TEG::Turno *turno);
    void ataque(TEG::Turno *turno);
    void reagrupe(TEG::Turno *turno);

    virtual float factorReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc);
    virtual float cantidadReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc);
    virtual float factorAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc);
    virtual float cantidadAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc);
    virtual int factorFichas(TEG::Turno *turno,TEG::Pais *pais);

    virtual bool next(TEG::Turno *turno);
protected:
    QList<TEG::Accion*> *getAcciones(TEG::Turno *turno, bool reagrupe );

    static bool sortingPais(const QPair<TEG::Pais*,int>& e1, const QPair<TEG::Pais*,int>& e2);
    static bool sortingAccion(const QPair<TEG::Accion*,int>& e1, const QPair<TEG::Accion*,int>& e2);
};

#endif // HEURISTICA_H
