#include "objetivo.h"
#include "utiles.h"

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
    int * conts = this->getContArray(paises);
    for ( int i = 0 ; i < 6 ; i++ )
        if ( this->continentes[i] > conts[i] ) return false;
    return true;
}

float TEG::Objetivo::factor(const QList<TEG::Pais*> *paises){
    int conqui = 0;
    int total = 0;
    int * conts = this->getContArray(paises);
    for ( int i = 0 ; i < 6 ; i++ ){
        total += this->continentes[i];
        if ( this->continentes[i] > conts[i] ) conqui += conts[i];
        else conqui += continentes[i];
    }
    return (conqui / total);
}

int TEG::Objetivo::restantes(const QList<TEG::Pais*> *paises){
    int resto = 0;
    int * conts = this->getContArray(paises);
    for ( int i = 0 ; i < 6 ; i++ )
        if ( this->continentes[i] > conts[i] ) resto += (this->continentes[i]-conts[i]);
    return resto;
}

int * TEG::Objetivo::getContArray(const QList<TEG::Pais*> *paises){
    int * conts = new int[6];
    conts = TEG::Utiles::integerArray(0,0,0,0,0,0);
    QList<TEG::Pais*>::const_iterator i;
    for (i = paises->begin(); i != paises->end(); ++i)
        conts[ (*i)->getContinenteID() ]++;
    return conts;
}
