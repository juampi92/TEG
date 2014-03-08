#ifndef INTELIGENCIAARTIFICIAL_H
#define INTELIGENCIAARTIFICIAL_H

#include "jugador.h"
#include "heuristicas/heuristica.h"

namespace TEG{
    class InteligenciaArtificial;
}

class TEG::InteligenciaArtificial : public TEG::Jugador
{
public:
    InteligenciaArtificial(TEG::Game *game, QString nom, int id, QString color, int IA=1);

    void playFichas(TEG::Turno *turno);
    void playAtaque(TEG::Turno *turno);

private:
    TEG::Heuristica *heuristica;
};

#endif // INTELIGENCIAARTIFICIAL_H
