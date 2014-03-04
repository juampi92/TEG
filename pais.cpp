#include "pais.h"

TEG::Pais::Pais(int id, QString nom, int cont){
    this->id = id;
    this->nom = nom;
    this->cont_id = cont;
    this->ejercitos = 0;
}

TEG::Pais::~Pais(){
}

bool TEG::Pais::continenteIgual(int cont){
    return ( this->cont_id == cont );
}

int TEG::Pais::getEjercitos(){
    return this->ejercitos;
}

int TEG::Pais::addEjercitos(int cant){
    this->ejercitos += cant;
    return this->ejercitos;
}

int TEG::Pais::removeEjercitos(int cant){
    this->ejercitos -= cant;
    return this->ejercitos;
}

void TEG::Pais::setOwner(TEG::Jugador *player){
    this->owner = player;
}

int TEG::Pais::getContinenteID() const{
    return this->cont_id;
}

int TEG::Pais::getID() const{
    return this->id;
}

TEG::Jugador * TEG::Pais::getOwner() const{
    return this->owner;
}

QString TEG::Pais::getName() const{
    return this->nom;
}
