#ifndef HEURISTICA_H
#define HEURISTICA_H

#include "../turno.h"

namespace TEG{
    class Heuristica;
 }
class TEG::Heuristica
{
public:
    Heuristica();

    void fichas(TEG::Turno *turno);
    void ataque(TEG::Turno *turno);
    void reagrupe(TEG::Turno *turno);
};

#endif // HEURISTICA_H
