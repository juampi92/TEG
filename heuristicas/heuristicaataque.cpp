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
    int hype=1;
    bool importante = turno->player->objetivo->favorece(turno->player->getContArray(),acc->getDestino());
    if( importante)
        hype += 10;
    QList<TEG::Pais*> * enemigos = turno->player->getLimitrofes((*acc).getOrigen()->getID(), false);
    int cantidadLmitrofes = turno->ronda->game->mapa->getCantLimitrofes((*acc).getOrigen()->getID());
    int cantidadEnemigosAdy = enemigos->size();
    float ratio = ((float)cantidadEnemigosAdy/cantidadLmitrofes)*10;
    hype *= ratio;

    return 10;
}

float TEG::HeuristicaAtaque::cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){
    return acc->getMax();
}

int TEG::HeuristicaAtaque::factorFichas(TEG::TurnoFichas *turno, QList<TEG::Pais *> *paises, TEG::Pais *pais){
    //Compara sobre esos paises. Si es un continente, los paises son los paises del continente. Si no, son todos
    //  los paises que posee
    int valor = 1;
    QList<TEG::Pais*> * enemigos = turno->player->getLimitrofes(pais->getID(), false);
    int cantidadLmitrofes = turno->ronda->game->mapa->getCantLimitrofes(pais->getID());
    int cantidadEnemigosAdy = enemigos->size();
    float ratio = ((float)cantidadEnemigosAdy/cantidadLmitrofes)*10;
    int fichasEnemigas=0;
    int fichasAmigas = pais->getEjercitos();
    for(QList<TEG::Pais*>::iterator it= enemigos->begin(); it != enemigos->end(); it++)
        fichasEnemigas += (*it)->getEjercitos()- 1;
    if(ratio == 0.0)
        return 0;
    else{
        int a = turno->player->objetivo->extra(turno->player->getContArray(),pais);
        qDebug() << " a: " << a ;
        if(a < 0)
            return ratio*(-a);
        else
            if(a=0){
                valor= (fichasEnemigas/2 - fichasAmigas);
                if(valor <= 0)
                    return 1;
                else
                    return valor;
            }
            else
                return 1;
        }
}

int TEG::HeuristicaAtaque::next(TEG::TurnoAtaques *turno, TEG::Pais * pais){
    // Si el número es mayor al máximo factor de ataque, entonces no se realiza la acción, y se pasa de turno.
    int danger = 0;
    QList<TEG::Pais*> * enemigos = turno->player->getLimitrofes(pais->getID(), false);
    int cantidadLmitrofes = turno->ronda->game->mapa->getCantLimitrofes(pais->getID());
    int cantidadEnemigosAdy = enemigos->size();
    int fichasEnemigas=0;
    int fichasAmigas = pais->getEjercitos();
    for(QList<TEG::Pais*>::iterator it= enemigos->begin(); it != enemigos->end(); it++)
        fichasEnemigas += (*it)->getEjercitos()- 1;

    if((fichasEnemigas/2 - fichasAmigas) > 0)
        return 1;
    else
        return danger;
}
