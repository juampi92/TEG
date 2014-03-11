#ifndef HEURISTICAMIX_H
#define HEURISTICAMIX_H

#include "heuristica.h"

namespace TEG{
    class HeuristicaMix;
}

class TEG::HeuristicaMix: public TEG::Heuristica
{
public:
    HeuristicaMix();

    float factorReagrupe(TEG::AccionReagrupe *acc);
    float cantidadReagrupe(TEG::AccionReagrupe *acc);
    float factorAtaque(TEG::AccionAtaque *acc);
    float cantidadAtaque(TEG::AccionAtaque *acc);

    bool next(TEG::Turno *turno);
};

#endif // HEURISTICAMIX_H
