#ifndef MAPA_H
#define MAPA_H

#include "game.h"

#include "continente.h"
#include "pais.h"

namespace TEG {
    class Game;
    class Mapa;
    class Continente;
    class Pais;
}

class TEG::Mapa
{
public:
    Mapa(TEG::Game *game);
    ~Mapa();

    TEG::Pais *getPais(int id);
    QList<TEG::Pais*> *getLimitrofes(int id);
    int getCantLimitrofes(int id);
    QList<TEG::Pais*> *getPaisesContinente(int id);

    TEG::Continente* continentes[6];
    TEG::Pais* paises[50];
    QList<TEG::Pais*>* relaciones[50];
    int paises_por_continente[6];

private:
    QList<TEG::Pais*>* setRelacionesAux(int,int=-1,int=-1,int=-1,int=-1,int=-1,int=-1,int=-1);
    TEG::Game *game;

};

#endif // MAPA_H
