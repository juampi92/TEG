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

    float factorReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    float cantidadReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc);
    float factorAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    float cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc);
    int factorFichas(TEG::TurnoFichas *turno, QList<TEG::Pais *> *paises, TEG::Pais *pais);

    int next(TEG::TurnoAtaques *turno, TEG::Pais * pais);
};

#endif // HEURISTICAATAQUE_H
