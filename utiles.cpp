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