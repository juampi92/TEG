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

    float factorReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc);
    float cantidadReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc);
    float factorAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc);
    float cantidadAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc);
    int factorFichas(TEG::Turno *turno,TEG::Pais *pais);

    bool next(TEG::Turno *turno);
};

#endif // HEURISTICAATAQUE_H
