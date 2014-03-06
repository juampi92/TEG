#include "turno.h"

TEG::Turno::Turno(TEG::RondaManager *ronda , TEG::Jugador *plyr){
    this->ronda = ronda;
    this->player = plyr;

}

TEG::Turno::~Turno(){
}

int TEG::Turno::getFichasDisp(){
    return 0;
}

void TEG::Turno::end(){
    this->ronda->game->gui->nextButton("Terminar turno");
}

void TEG::Turno::play(){}
void TEG::Turno::paisClick(int id){}
void TEG::Turno::startTurno(){} // Sobre escrita por los hijos
