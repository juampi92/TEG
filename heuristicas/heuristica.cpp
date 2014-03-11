#include "heuristica.h"

TEG::Heuristica::Heuristica()
{
}

TEG::Heuristica::~Heuristica(){
}

void TEG::Heuristica::fichas(TEG::Turno *turno){
    QList<QPair<TEG::Pais*,int> > *lista;

    QList<TEG::Pais*> * paises = turno->player->getListPaises();
    for ( QList<TEG::Pais*>::iterator i = paises->begin() ; i != paises->end() ; i++ ){
        QPair<TEG::Pais*,int> par;
        par.first = (*i);
        par.second = this->factorFichas(turno,par.first);
        lista->append(par);
    }

    qSort(lista->begin(), lista->end(), TEG::Heuristica::sortingPais);

    // PONER LAS FICHAS :D (TODAS si o si). No olvidarse de repartir en el continente.

    // Eliminar la lista.
}

void TEG::Heuristica::ataque(TEG::Turno *turno){
    // Pregunto si quiero pasar (next()). Si no:

    // Usar get Acciones, y a cada acción aplicar la heurística (de ataque)

    // Ordenar las acciones con qSort y TEG::Heuristica::sortingAcciones

    // ejecutar la primera acción
}

void TEG::Heuristica::reagrupe(TEG::Turno *turno){
    // Pregunto si quiero pasar (next()). Si no:

    // Usar get Acciones, y a cada acción, aplicar la heurística (de reagrupe)

    // Ordenar las acciones con qSort y TEG::Heuristica::sortingAcciones

    // ejecutar la primera acción
}

QList<TEG::Accion*> *TEG::Heuristica::getAcciones(TEG::Turno *turno, bool reagrupe ){
    QList<TEG::Accion*> *lista = new QList<TEG::Accion*>();
    QList<TEG::Pais*> * paises = turno->player->getListPaises(true);
    for ( QList<TEG::Pais*>::iterator i = paises->begin() ; i != paises->end() ; i++ ){
        QList<TEG::Pais*> * limitrofes = turno->player->getLimitrofes((*i)->getID(),reagrupe);
        for ( QList<TEG::Pais*>::iterator j = limitrofes->begin() ; j != limitrofes->end() ; j++ ){
            TEG::Accion * accion;
            if ( reagrupe ) accion = new TEG::AccionReagrupe((*i),(*j),turno->ronda->game,turno);
            else accion = new TEG::AccionAtaque((*i),(*j),turno->ronda->game);
            lista->append(accion);
        }
    }
    return lista;
}

float TEG::Heuristica::factorReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc){return 0;}
float TEG::Heuristica::cantidadReagrupe(TEG::Turno *turno,TEG::AccionReagrupe *acc){return 0;}
float TEG::Heuristica::factorAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc){return 0;}
float TEG::Heuristica::cantidadAtaque(TEG::Turno *turno,TEG::AccionAtaque *acc){return 0;}
int TEG::Heuristica::factorFichas(TEG::Turno *turno,TEG::Pais *pais){return 0;}
bool TEG::Heuristica::next(TEG::Turno *turno){return false;}


bool TEG::Heuristica::sortingPais(const QPair<TEG::Pais*,int>& e1, const QPair<TEG::Pais*,int>& e2) { // sorting by QHash Value
    return ( e1.second < e2.second );
}

bool TEG::Heuristica::sortingAccion(const QPair<TEG::Accion*,int>& e1, const QPair<TEG::Accion*,int>& e2) { // sorting by QHash Value
    return ( e1.second < e2.second );
}
