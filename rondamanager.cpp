#include "rondamanager.h"

#include "turnoataques.h"
#include "turnofichas.h"

TEG::RondaManager::RondaManager(Game *juego, QList<Jugador *> *players){
    this->game = juego;
    this->begin = players->begin();
    this->actual = this->begin;
}

TEG::RondaManager::~RondaManager(){
}

void TEG::RondaManager::start(){
    this->setType(0);
    this->turno->play();
}

void TEG::RondaManager::end(){

}

void TEG::RondaManager::nextTurno(){

}

void TEG::RondaManager::playTurno(){
    this->turno->play();
}

void TEG::RondaManager::setType(int t){
    this->type = t;
    this->game->gui->setRoundType(t);

    /*if ( this->turno != nullptr ) delete this->turno;*/

    if ( t == 0 )
        this->turno = new TEG::TurnoFichas(this,*this->actual);
    else if ( t == 1 )
        this->turno = new TEG::TurnoAtaques(this,*this->actual);
}

void TEG::RondaManager::btnClick(int id){
    //if ( this->turno == NULL ) return;
    // Valida si es un Bot. Si es un bot, no podés intervenir en el tablero.
    this->turno->paisClick(id);
}
