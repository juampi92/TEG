#ifndef UTILES_H
#define UTILES_H

#include "pais.h"

namespace TEG{
    class Utiles;
}

class TEG::Utiles
{
public:
    static int getRandom(int max);
    static TEG::Pais **shuffle(TEG::Pais **arr , int length);
};

#endif // UTILES_H
