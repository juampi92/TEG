#ifndef MAPA_H
#define MAPA_H

#include "game.h"

#include "continente.h"
#include "pais.h"

namespace TEG {
    class Game;
    class Mapa;
}

class TEG::Mapa
{
public:
    Mapa(TEG::Game *game);
    ~Mapa();

private:
    TEG::Game *game;
    TEG::Continente** continentes;
    TEG::Pais** paises;
    QList<TEG::Pais*>** relaciones;

};

#endif // MAPA_H
