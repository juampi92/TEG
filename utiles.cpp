#include <QtGlobal>
#include "utiles.h"


int TEG::Utiles::getRandom(int max){
    return qrand() % max;
}

TEG::Pais **TEG::Utiles::shuffle(TEG::Pais **arr , int length){
    TEG::Pais ** aux = new TEG::Pais*[length];
    for ( int i = 0 ; i < length ; i++ )
        aux[i] = arr[i];

    TEG::Pais * buf;
    int rand;
    for ( int j = 0 ; j < length ; j++ ) {
        rand = TEG::Utiles::getRandom(length);
        buf = aux[j];
        aux[j] = aux[rand];
        aux[rand] = buf;
    }
    return aux;
}

TEG::Objetivo **TEG::Utiles::shuffle(TEG::Objetivo **arr , int length){
    TEG::Objetivo ** aux = new TEG::Objetivo*[length];
    for ( int i = 0 ; i < length ; i++ )
        aux[i] = arr[i];

    TEG::Objetivo * buf;
    int rand;
    for ( int j = 0 ; j < length ; j++ ) {
        rand = TEG::Utiles::getRandom(length);
        buf = aux[j];
        aux[j] = aux[rand];
        aux[rand] = buf;
    }
    return aux;
}

QList<int> TEG::Utiles::getRandomList(int cant, int max){
    QList<int> out;
    for ( int i = 0 ; i < cant ; i++ )
        out.append(TEG::Utiles::getRandom(max)+1); // +1 evita los 0. Usado para los dados
    return out;
}

QList<int> * TEG::Utiles::toIntList(QList<TEG::Pais*> *paises){
    QList<int> * retorno = new QList<int>();

    QList<TEG::Pais*>::iterator i;
    for ( i = paises->begin() ; i != paises->end() ; i++ ){
        retorno->append((*i)->getID());
    }

    return retorno;
}
