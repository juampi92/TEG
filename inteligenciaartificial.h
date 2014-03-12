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

    int getIA();

    void playFichas(TEG::Turno *turno);
    void playAtaque(TEG::Turno *turno);
    void playReagrupe(TEG::Turno * turno);

    int playReagrupeCant(TEG::Turno * turno, TEG::Accion *acc);
    int playConquistaCant(TEG::Turno * turno, TEG::Accion *acc);

private:
    TEG::Heuristica *heuristica;
    int IA_type;
};

#endif // INTELIGENCIAARTIFICIAL_H
