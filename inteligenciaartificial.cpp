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
    this->IA_type = IA;
}

int TEG::InteligenciaArtificial::getIA(){
    return this->IA_type;
}

void TEG::InteligenciaArtificial::playFichas(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->heuristica->fichas( (TEG::TurnoFichas*) turno);
}

void TEG::InteligenciaArtificial::playAtaque(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->heuristica->ataque( (TEG::TurnoAtaques*) turno);
}

void TEG::InteligenciaArtificial::playReagrupe(TEG::Turno * turno){
    this->game->gui->allEnabled(false);
    this->heuristica->reagrupe((TEG::TurnoAtaques*)turno);
}

int TEG::InteligenciaArtificial::playReagrupeCant(TEG::Turno * turno, TEG::Accion *acc){
    return this->heuristica->cantidadReagrupe((TEG::TurnoAtaques*) turno,(TEG::AccionReagrupe*) acc);
}

int TEG::InteligenciaArtificial::playConquistaCant(TEG::Turno * turno, TEG::Accion *acc){
    return this->heuristica->cantidadAtaque((TEG::TurnoAtaques*) turno,(TEG::AccionAtaque*) acc);
}
