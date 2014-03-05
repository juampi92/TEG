#ifndef UTILES_H
#define UTILES_H

#include "pais.h"
#include "objetivo.h"

namespace TEG{
    class Utiles;
    class Objetivo;
}

class TEG::Utiles
{
public:
    static int getRandom(int max);
    static TEG::Pais **shuffle(TEG::Pais **arr , int length);
    static TEG::Objetivo **shuffle(TEG::Objetivo **arr , int length);
};
#endif // UTILES_H
