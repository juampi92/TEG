#include "objetivo.h"

TEG::Objetivo::Objetivo(int id, QString descr, int *obj){
    this->id = id;
    this->descr = descr;
    this->continentes = obj;
}

TEG::Objetivo::~Objetivo(){
}

QString TEG::Objetivo::showObjetivo() const{
    return this->descr;
}

bool TEG::Objetivo::cumplio(const QList<TEG::Pais*> *paises){
    return false;
}

float TEG::Objetivo::factor(const QList<TEG::Pais*> *paises){
    return 0;
}

int TEG::Objetivo::restantes(const QList<TEG::Pais*> *paises){
    return 0;
}

int * TEG::Objetivo::getContArray(const QList<TEG::Pais*> *paises){
    int conts[6] = {0,0,0,0,0,0};
    QList<TEG::Pais*>::const_iterator i;
    for (i = paises->begin(); i != paises->end(); ++i)
        conts[ (*i)->getContinenteID() ]++;
    return conts;
}
