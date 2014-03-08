#include "turnoataques.h"
#include "utiles.h"

TEG::TurnoAtaques::TurnoAtaques(TEG::RondaManager *ronda, TEG::Jugador *plyr) : TEG::Turno(ronda,plyr){
    this->startTurno();
    this->reagrupe= false;
    this->origen = NULL;
    this->destino = NULL;
    this->ronda->game->gui->setAttackButton(false,true);
    this->ronda->game->gui->nextButton("Reagupar");
}

TEG::TurnoAtaques::~TurnoAtaques(){

}

void TEG::TurnoAtaques::play(){
    TEG::Turno::play();
}

bool TEG::TurnoAtaques::next(){
    if ( this->reagrupe ) return true;

    this->reagrupe = true;
    this->ronda->game->gui->setAttackButton(false,false);
    this->ronda->game->gui->nextButton("Terminar Turno");
    return false;
}

void TEG::TurnoAtaques::paisClick(int id){
    if(this->origen == NULL){
        this->origen = this->ronda->game->mapa->getPais(id);
        this->selectOrigen(id,reagrupe);
    }
    else
        if ( this->origen->getID() != id && this->destino == NULL ){
            this->origen == NULL;
            this->play();
        } else if(this->destino->getID()== id){
            this->destino = NULL;
            this->selectOrigen(this->origen->getID(),reagrupe);
        } else if(this->destino == NULL){
            this->destino = this->ronda->game->mapa->getPais(id);
            this->selectDestino(id);

            // Habilitar ataque.
            this->ronda->game->gui->setAttackButton(true);
            return;
        }
    this->ronda->game->gui->setAttackButton(false);
}

void TEG::TurnoAtaques::btnAttack(){
    if ( this->reagrupe ){
        qDebug() << "REAGRUPAR";
    } else {
        qDebug() << "ATACAR!";
    }
}

void TEG::TurnoAtaques::startTurno(){
    this->player->playAtaque(this);
}

void TEG::TurnoAtaques::selectOrigen(int id, bool friends){
    this->ronda->game->gui->allEnabled(false);
    this->ronda->game->gui->setPaisSelected(id,true);
    QList<TEG::Pais*> * limitrofes = this->player->getLimitrofes(id,friends);
    QList<TEG::Pais*>::iterator it = limitrofes->begin();
    for(it; it != limitrofes->end(); it++)
        this->ronda->game->gui->setPaisEnabled((*it)->getID(),true);
}

void TEG::TurnoAtaques::selectDestino(int id){
    this->ronda->game->gui->allEnabled(false);
    this->ronda->game->gui->setPaisSelected(this->origen->getID(),true);
    this->ronda->game->gui->setPaisSelected(id,true);
}
