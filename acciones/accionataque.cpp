#include "accionataque.h"
#include "../utiles.h"

TEG::AccionAtaque::AccionAtaque(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game) : TEG::Accion(origen,destino,game){
    this->fichas.orig = this->fichas.dest = 0;
}

TEG::AccionAtaque::~AccionAtaque(){}

bool TEG::AccionAtaque::validar(){
    if ( origen->getEjercitos() > 1 && origen->getOwner()->getID() != destino->getOwner()->getID() )
        return true;
    return false;
}
void TEG::AccionAtaque::calcularFichas(){
    if ( this->fichas.orig != 0 ) return;
    // Calcular el ataque, y ganador
    if( this->origen->getEjercitos()-1 > 3 ) this->fichas.orig = 3; else this->fichas.orig = this->origen->getEjercitos()-1;
    if( this->destino->getEjercitos() > 3 ) this->fichas.dest = 3; else this->fichas.dest = this->destino->getEjercitos();
}

void TEG::AccionAtaque::execute(){
    this->win = false;
    // Borrar display ultimo ataque.
    this->game->gui->clearAtaque();
    this->game->gui->setAtaque(this->origen->getName() , this->destino->getName() );

    this->calcularFichas();

    QList<int> dadosOrig = TEG::Utiles::getRandomList( this->fichas.orig , 6 );
    QList<int> dadosDest = TEG::Utiles::getRandomList( this->fichas.dest , 6 );

    qSort(dadosOrig.begin(), dadosOrig.end(), qGreater<int>());
    qSort(dadosDest.begin(), dadosDest.end(), qGreater<int>());

    //Detectar ganador
    this->fichas.orig = this->fichas.dest = 0; //Pasan a ser los ejercitos PERDIDOS por cada uno
    for ( int it = 0 ; it < qMin(dadosOrig.count(),dadosDest.count()) ; it++)
        if ( dadosOrig.at(it) > dadosDest.at(it) ) this->fichas.dest++; else this->fichas.orig++;

    if ( this->fichas.dest == this->destino->getEjercitos() ) this->win = true;

    // Mostrar el ataque
    this->game->gui->vaciarDados();
    this->game->gui->setDados(dadosOrig,dadosDest);
}

bool TEG::AccionAtaque::endAnimacion(){
    // Ejecutar las bajas de ejercitos:

    //qDebug() << "Perdidas de: Origen: " << this->fichas.orig << " - Destino: " << this->fichas.dest;

    this->game->gui->setPaisFichas(this->origen->getID() , this->origen->removeEjercitos(this->fichas.orig) );
    this->game->gui->setPaisFichas(this->destino->getID() , this->destino->removeEjercitos(this->fichas.dest) );

    // Si ganó: Preguntar cuántas pasar
    if ( win ) {
        int cant = this->origen->getOwner()->playConquistaCant(this,this->getMax());
        this->destino->getOwner()->removePais(this->destino);
        this->destino->setOwner(this->origen->getOwner());
        this->origen->getOwner()->addPais(this->destino);
        this->game->gui->setPaisColor(this->destino->getID() , this->origen->getOwner()->getColor() );
        this->game->gui->setPaisFichas(this->destino->getID() , this->destino->setEjercitos(cant));
        this->game->gui->setPaisFichas(this->origen->getID() , this->origen->removeEjercitos(cant));
        return true;
    } else
        if ( this->origen->getEjercitos() == 1 ) return true;
        else return false;
}


float TEG::AccionAtaque::prob(){
    this->calcularFichas();
    return 0;
}

int TEG::AccionAtaque::getMax(){
    int ejer = this->origen->getEjercitos();
    if ( ejer-1 >= 3 ) return 3; else return ejer-1;
}
