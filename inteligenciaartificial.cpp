#include "inteligenciaartificial.h"
#include "heuristicas/heuristicaataque.h"
#include "heuristicas/heuristicadefensa.h"
#include "heuristicas/heuristicamix.h"

TEG::InteligenciaArtificial::InteligenciaArtificial(Game *game, QString nom, int id, QString color, int IA) :
    TEG::Jugador(game,nom,id,color){
    switch(IA){
        case 1: this->heuristica = new TEG::HeuristicaAtaque(); break;
        case 2: this->heuristica = new TEG::HeuristicaDefensa(); break;
        case 3: this->heuristica = new TEG::HeuristicaMix(); break;
    }
}

void TEG::InteligenciaArtificial::playFichas(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->heuristica->fichas(turno);
}

void TEG::InteligenciaArtificial::playAtaque(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->heuristica->ataque(turno);
}
