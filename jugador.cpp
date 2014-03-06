#include "jugador.h"

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

QString TEG::Jugador::getColor(){
    return this->color;
}

QString TEG::Jugador::getName(){
    return this->nom;
}

QList<TEG::Pais*> *TEG::Jugador::getListPaises(){
    return this->paises;
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

void TEG::Jugador::setObjetivo(TEG::Objetivo *obj){
    this->objetivo = obj;
}

void TEG::Jugador::addPais(TEG::Pais *pais){
    this->paises->append(pais);
}
