#include "jugador.h"

TEG::Jugador::Jugador(TEG::Game *game, QString nom, int id, QString color){
    this->game = game;
    this->nom = nom;
    this->id = id;
    this->color = color;
}

TEG::Jugador::~Jugador(){
}

QString TEG::Jugador::getColor(){
    return this->color;
}

QString TEG::Jugador::getName(){
    return this->nom;
}
