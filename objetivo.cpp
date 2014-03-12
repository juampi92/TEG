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
    return this->cumplio(this->getContArray(paises));
}

bool TEG::Objetivo::cumplio(const int *conts){
    for ( int i = 0 ; i < 6 ; i++ )
        if ( this->continentes[i] > conts[i] ) return false;
    return true;
}

float TEG::Objetivo::factor(const QList<TEG::Pais*> *paises){
    return this->factor(this->getContArray(paises));
}

float TEG::Objetivo::factor(const int *conts){
    int conqui = 0;
    int total = 0;
    for ( int i = 0 ; i < 6 ; i++ ){
        total += this->continentes[i];
        if ( this->continentes[i] > conts[i] ) conqui += conts[i];
        else conqui += continentes[i];
    }
    float ret = conqui;
    return ret / total;
}

int TEG::Objetivo::restantes(const QList<TEG::Pais*> *paises){
    return this->restantes(this->getContArray(paises));
}

int TEG::Objetivo::restantes(const int *conts){
    int resto = 0;
    for ( int i = 0 ; i < 6 ; i++ )
        if ( this->continentes[i] > conts[i] ) resto += (this->continentes[i]-conts[i]);
    return resto;
}

bool TEG::Objetivo::favorece(int *conts, TEG::Pais* pais){
    if ( this->continentes[pais->getContinenteID()] >= (conts[pais->getContinenteID()]+1) ) return true;
    return false;
}

int TEG::Objetivo::extra(int *conts, TEG::Pais* pais){
    return ( conts[pais->getContinenteID()] - this->continentes[pais->getContinenteID()] );
}

int * TEG::Objetivo::getContArray(const QList<TEG::Pais*> *paises){
    int * conts = new int[6];
    conts = TEG::Utiles::integerArray(0,0,0,0,0,0);
    QList<TEG::Pais*>::const_iterator i;
    for (i = paises->begin(); i != paises->end(); ++i)
        conts[ (*i)->getContinenteID() ]++;
    return conts;
}
