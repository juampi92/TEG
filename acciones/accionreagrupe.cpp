#include "accionreagrupe.h"

TEG::AccionReagrupe::AccionReagrupe(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game, TEG::Turno *turno) : TEG::Accion(origen,destino,game){
    this->turno = turno;
}
TEG::AccionReagrupe::~AccionReagrupe(){}

bool TEG::AccionReagrupe::validar(){
    if ( origen->getOwner()->getID() == destino->getOwner()->getID() && this->getMax() > 0 )
        return true;
    return false;
}
void TEG::AccionReagrupe::execute(){
    // Preguntar cuántas pasar
    int cant = this->origen->getOwner()->playReagrupeCant(this->turno,this);
    qDebug() << "Cantidad: " << cant << ". Max: " << this->getMax();
    // Actualizar paises involucrados.
    this->game->gui->setPaisFichas(this->origen->getID() , this->origen->removeEjercitos(cant) );
    this->game->gui->setPaisFichas(this->destino->getID() , this->destino->addEjercitos(cant) );
}
int TEG::AccionReagrupe::getMax(){
    // calcular el máximo. Se necesitan los movimientos anteriores.
    return this->origen->getEjercitos()-1;
}
