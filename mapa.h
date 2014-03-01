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
    TEG::Continente** continentes = new TEG::Continente*[6];
    TEG::Pais** paises = new TEG::Pais*[50];
    QList<TEG::Pais*>** relaciones = new QList<TEG::Pais*>*[50];

};

#endif // MAPA_H
