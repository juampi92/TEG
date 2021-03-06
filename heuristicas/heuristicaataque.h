#ifndef HEURISTICAATAQUE_H
#define HEURISTICAATAQUE_H

#include "heuristica.h"

namespace TEG{
    class HeuristicaAtaque;
 }

class TEG::HeuristicaAtaque: public TEG::Heuristica
{
public:
    HeuristicaAtaque();
    ~HeuristicaAtaque();

    int factorReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    float cantidadReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    int factorAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    float cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    int factorFichas(TEG::TurnoFichas *turno, TEG::Pais *pais);

    int next(TEG::TurnoAtaques *turno, TEG::Pais * pais);
    int nextReagrupe(TEG::TurnoAtaques *turno, TEG::AccionReagrupe *acc);
};

#endif // HEURISTICAATAQUE_H
