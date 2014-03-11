#include "continente.h"

TEG::Continente::Continente(QString nom, int id){
    this->nom = nom;
    this->id = id;
}

TEG::Continente::~Continente(){
}

QList<TEG::Pais*> *TEG::Continente::getPaises(){
    return this->paises;
}

void TEG::Continente::setPaises(QList<TEG::Pais*> *lista){
    this->paises = lista;
}
