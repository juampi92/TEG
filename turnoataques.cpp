#include "turnoataques.h"
#include "utiles.h"

TEG::TurnoAtaques::TurnoAtaques(TEG::RondaManager *ronda, TEG::Jugador *plyr) : TEG::Turno(ronda,plyr){
    this->startTurno();
}

TEG::TurnoAtaques::~TurnoAtaques(){

}

void TEG::TurnoAtaques::startTurno(){
    qDebug() << 3;
    //this->game->gui->allEnabled(false);
    //this->game->gui->setPaisesEnabled(this->toIntList(this->getBorderEnemies(id,this->jugadores->at(0))),true);
    //this->game->gui->setPaisSelected(id,true);
    this->ronda->game->gui->setPaisesEnabled(TEG::Utiles::toIntList(this->player->getListPaises()),true);
}

