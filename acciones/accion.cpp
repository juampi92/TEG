#include "accion.h"

TEG::Accion::Accion(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game){
    this->origen = origen;
    this->destino = destino;
    this->game = game;
}

TEG::Accion::~Accion(){}

bool TEG::Accion::validar(){return false;}
void TEG::Accion::execute(){}
float TEG::Accion::prob(){return 0;}
int TEG::Accion::getMax(){return 0;}
bool TEG::Accion::endAnimacion(){return true;}

TEG::Pais * TEG::Accion::getOrigen(){
    return this->origen;
}

TEG::Pais * TEG::Accion::getDestino(){
    return this->destino;
}
