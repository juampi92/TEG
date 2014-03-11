#ifndef HEURISTICADEFENSA_H
#define HEURISTICADEFENSA_H

#include "heuristica.h"

namespace TEG{
    class HeuristicaDefensa;
 }

class TEG::HeuristicaDefensa: public TEG::Heuristica
{
public:
    HeuristicaDefensa();

    float factorReagrupe(TEG::AccionReagrupe *acc);
    float cantidadReagrupe(TEG::AccionReagrupe *acc);
    float factorAtaque(TEG::AccionAtaque *acc);
    float cantidadAtaque(TEG::AccionAtaque *acc);

    bool next(TEG::Turno *turno);
};

#endif // HEURISTICADEFENSA_H
