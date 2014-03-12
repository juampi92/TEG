#include "turno.h"

TEG::Turno::Turno(TEG::RondaManager *ronda , TEG::Jugador *plyr){
    this->ronda = ronda;
    this->player = plyr;
    this->ronda->game->gui->nextButton("");
}

TEG::Turno::~Turno(){
}

int TEG::Turno::getFichasDisp(){
    return 0;
}

void TEG::Turno::end(){
    this->ronda->game->gui->nextButton("Terminar turno");
}

void TEG::Turno::play(){
    this->ronda->game->gui->setTurno(this->player->getID(),this->ronda->game->getCantPlayers());
    this->ronda->game->gui->setPlayerInfo(this->player->getName(),this->player->getCantPaises(),this->player->getCantEjercitos(),this->getFichasDisp());
}

void TEG::Turno::paisClick(int id){}
void TEG::Turno::btnAttack(){}
void TEG::Turno::startTurno(){} // Sobre escrita por los hijos
bool TEG::Turno::next(){return true;}
void TEG::Turno::endDadosAnimacion(){}
