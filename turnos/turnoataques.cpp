#include "turnoataques.h"
#include "utiles.h"

#include <QtAlgorithms>

TEG::TurnoAtaques::TurnoAtaques(TEG::RondaManager *ronda, TEG::Jugador *plyr) : TEG::Turno(ronda,plyr){
    this->reagrupe= false;
    this->origen = NULL;
    this->destino = NULL;
    this->ronda->game->gui->setAttackButton(false,true);
    this->ronda->game->gui->nextButton("Reagupar");

    this->ataques = new QList<TEG::AccionAtaque*>();
    this->reagrupes = new QList<TEG::AccionReagrupe*>();
}

TEG::TurnoAtaques::~TurnoAtaques(){
    // FALLA AL BORRAR!!

    /*int cant = this->ataques->count();
    for (int i=0; i< cant; i++)
        delete ( (TEG::AccionAtaque*) this->ataques->takeAt(0));

    cant = this->reagrupes->count();
    for (int i=0; i< cant; i++)
        delete ( (TEG::AccionReagrupe*) this->reagrupes->takeAt(0));*/

    /*qDeleteAll(*this->ataques);
    qDeleteAll(*this->reagrupes);*/

    this->ataques->clear();
    this->reagrupes->clear();
}

void TEG::TurnoAtaques::play(){
    TEG::Turno::play();
    this->startTurno();
}

bool TEG::TurnoAtaques::next(){
    if ( this->reagrupe ) return true;

    this->origen = this->destino = NULL;

    this->reagrupe = true;
    this->startTurno();
    this->ronda->game->gui->setAttackButton(false,false);
    this->ronda->game->gui->nextButton("Terminar Turno");
    return false;
}

void TEG::TurnoAtaques::paisClick(int id){
    if(this->origen == NULL){
        //qDebug() << "Origen selected";
        this->origen = this->ronda->game->mapa->getPais(id);
        this->selectOrigen(id,reagrupe);
    }
    else if ( this->origen->getID() == id && this->destino == NULL ){
        //qDebug() << "Origen des-selected";
        this->origen = NULL;
        this->startTurno();
    } else if(this->destino == NULL){
        //qDebug() << "Destino selected";
        this->destino = this->ronda->game->mapa->getPais(id);
        this->selectDestino(id);

        // Habilitar ataque.
        this->ronda->game->gui->setAttackButton(true);
        return;
    } else if(this->destino->getID()== id){
        //qDebug() << "Destino des-selected";
        this->destino = NULL;
        this->selectOrigen(this->origen->getID(),reagrupe);
    }
    this->ronda->game->gui->setAttackButton(false);
}

void TEG::TurnoAtaques::btnAttack(){
    if ( this->reagrupe ){
        TEG::AccionReagrupe *acc = new TEG::AccionReagrupe(this->origen,this->destino,this->ronda->game,this);
        this->setAccion(acc);
        if ( ! this->currentAction->validar() ){ this->startTurno(); return; }
        this->currentAction->execute();
        this->reagrupes->append(acc);
    } else {
        this->setAccion(new TEG::AccionAtaque(this->origen,this->destino,this->ronda->game));
        if ( ! this->currentAction->validar() ){ this->startTurno(); return; }
        this->currentAction->execute();
    }
}

void TEG::TurnoAtaques::startTurno(){
    this->origen = NULL; this->destino = NULL;
    if(this->reagrupe) this->player->playReagrupe(this);
    else this->player->playAtaque(this);
}

void TEG::TurnoAtaques::selectOrigen(int id, bool friends){
    this->ronda->game->gui->allEnabled(false);
    this->ronda->game->gui->setPaisSelected(id,true);
    QList<TEG::Pais*> * limitrofes = this->player->getLimitrofes(id,friends);
    QList<TEG::Pais*>::iterator it;
    for(it = limitrofes->begin(); it != limitrofes->end(); it++)
        this->ronda->game->gui->setPaisEnabled((*it)->getID(),true);
}

void TEG::TurnoAtaques::selectDestino(int id){
    this->ronda->game->gui->allEnabled(false);
    this->ronda->game->gui->setPaisSelected(this->origen->getID(),true);
    this->ronda->game->gui->setPaisSelected(id,true);
}

void TEG::TurnoAtaques::endDadosAnimacion(){
    if ( this->currentAction->endAnimacion() || this->player->getIA() > 0 ) {
        this->origen = this->destino = NULL;
        this->startTurno();
    }

    this->ronda->game->gui->setPlayerInfo("",this->player->getCantPaises(),this->player->getCantEjercitos());

    this->ataques->append( (TEG::AccionAtaque*) this->currentAction);
}

void TEG::TurnoAtaques::setAccion(TEG::Accion * accion){
    this->currentAction = accion;
}
