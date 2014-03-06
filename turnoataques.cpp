#include "turnoataques.h"
#include "utiles.h"

TEG::TurnoAtaques::TurnoAtaques(TEG::RondaManager *ronda, TEG::Jugador *plyr) : TEG::Turno(ronda,plyr){
    this->startTurno();
}

TEG::TurnoAtaques::~TurnoAtaques(){

}

void TEG::TurnoAtaques::play(){
    TEG::Turno::play();
}

void TEG::TurnoAtaques::startTurno(){
    this->player->playAtaque(this);
}

