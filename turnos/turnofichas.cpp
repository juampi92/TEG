#include "turnofichas.h"
#include "utiles.h"

TEG::TurnoFichas::TurnoFichas(TEG::RondaManager *ronda, TEG::Jugador *plyr, int spec) : TEG::Turno(ronda,plyr){
    this->startTurno();
    if ( spec > 0 )
        this->fichasDisp = spec;
    else
        this->fichasDisp = this->calcularFichas();
}

TEG::TurnoFichas::~TurnoFichas(){

}

void TEG::TurnoFichas::play(){
    TEG::Turno::play();
}

void TEG::TurnoFichas::paisClick(int id){
    this->agregarFicha(this->ronda->game->mapa->getPais(id));
}

void TEG::TurnoFichas::agregarFicha(TEG::Pais *pais){
    // Validación:
    if ( pais->getOwner()->getID() != this->player->getID() || this->fichasDisp <= 0 )
        return; // No es tu país
    // Acción:
    this->ronda->game->gui->setPaisFichas(pais->getID(),pais->addEjercitos(+1));
    this->fichasDisp--;

    this->ronda->game->gui->setPlayerInfo("",-1,this->player->getCantEjercitos(),this->getFichasDisp());

    if ( this->fichasDisp == 0 ) this->end();
}

int TEG::TurnoFichas::getFichasDisp(){
    return this->fichasDisp;
}

void TEG::TurnoFichas::startTurno(){
    this->player->playFichas(this);
}

int TEG::TurnoFichas::calcularFichas(){
    int f = this->player->getCantPaises() / 2;
    if ( f < 3 ) f = 3; // Minimo.
    return f;
}