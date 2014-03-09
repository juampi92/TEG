#include "jugador.h"
#include "utiles.h"

TEG::Jugador::Jugador(TEG::Game *game, QString nom, int id, QString color){
    this->game = game;
    this->nom = nom;
    this->id = id;
    this->color = color;
    this->paises = new QList<TEG::Pais*>();
}

TEG::Jugador::~Jugador(){
}

int TEG::Jugador::getID(){
    return this->id;
}

int TEG::Jugador::getIA(){ return 0;}

QString TEG::Jugador::getColor(){
    return this->color;
}

QString TEG::Jugador::getName(){
    return this->nom;
}

QList<TEG::Pais*> *TEG::Jugador::getListPaises(bool hasFichas){
    if ( ! hasFichas )
        return this->paises;
    else {
        QList<TEG::Pais*> * out = new QList<TEG::Pais*>();
        for ( QList<TEG::Pais*>::iterator i = this->paises->begin() ; i != this->paises->end() ; i++ )
            if ( (*i)->getEjercitos() > 1 ) out->append((*i));
        return out;
    }
}

int TEG::Jugador::getCantPaises(){
    return this->paises->size();
}

int TEG::Jugador::getCantEjercitos(){
    int cont = 0;
    QList<TEG::Pais*>::iterator i;
    for ( i = this->paises->begin() ; i != this->paises->end() ; i++ )
        cont += (*i)->getEjercitos();
    return cont;
}

QList<TEG::Pais*> * TEG::Jugador::getLimitrofes(int id, bool friends){
    // Devuelve un listado de los paises amigos (o enemigos) limitrofes al seleccionado.
    QList<TEG::Pais*> * lim = this->game->mapa->getLimitrofes(id);
    QList<TEG::Pais*> * retorno = new QList<TEG::Pais*>();

    QList<TEG::Pais*>::iterator i;

    for ( i = lim->begin() ; i != lim->end() ; i++ )
        if ( (friends && ((*i)->getOwner()->getID() == this->getID() ))
             || (!friends && ((*i)->getOwner()->getID() != this->getID())))
            retorno->append((*i));

    return retorno;
}

void TEG::Jugador::setObjetivo(TEG::Objetivo *obj){
    this->objetivo = obj;
}

QString TEG::Jugador::showObjetivo() const{
    return this->objetivo->showObjetivo();
}

void TEG::Jugador::addPais(TEG::Pais *pais){
    this->paises->append(pais);
}

void TEG::Jugador::removePais(TEG::Pais *pais){
    this->paises->removeOne(pais);
}

void TEG::Jugador::playFichas(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->game->gui->setPaisesEnabled(TEG::Utiles::toIntList(this->getListPaises()),true);
}

void TEG::Jugador::playAtaque(TEG::Turno *turno){
    this->game->gui->allEnabled(false);
    this->game->gui->setPaisesEnabled(TEG::Utiles::toIntList(this->getListPaises(true)),true);
}

int TEG::Jugador::playReagrupeCant(TEG::Accion *acc, int max){
    return this->game->gui->popUpFichas(2,acc->getOrigen()->getName(),acc->getDestino()->getName(),1,max);
}
int TEG::Jugador::playConquistaCant(TEG::Accion *acc, int max){
    return this->game->gui->popUpFichas(1,acc->getOrigen()->getName(),acc->getDestino()->getName(),1,max);
}
