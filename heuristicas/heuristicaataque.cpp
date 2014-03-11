#include "heuristicaataque.h"

TEG::HeuristicaAtaque::HeuristicaAtaque()
{
}
TEG::HeuristicaAtaque::~HeuristicaAtaque()
{
}

float TEG::HeuristicaAtaque::factorReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc){

}

float TEG::HeuristicaAtaque::cantidadReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc){
    return acc->getMax();
}

float TEG::HeuristicaAtaque::factorAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){

}

float TEG::HeuristicaAtaque::cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){
    return acc->getMax();
}

int TEG::HeuristicaAtaque::factorFichas(TEG::TurnoFichas *turno, QList<TEG::Pais *> *paises, TEG::Pais *pais){
    //Compara sobre esos paises. Si es un continente, los paises son los paises del continente. Si no, son todos
    //  los paises que posee
}

int TEG::HeuristicaAtaque::next(TEG::TurnoAtaques *turno){
    // Si el número es mayor al máximo factor de ataque, entonces no se realiza la acción, y se pasa de turno.

}
