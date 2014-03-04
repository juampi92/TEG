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

void TEG::Jugador::addPais(TEG::Pais *pais){
    this->paises->append(pais);
}
