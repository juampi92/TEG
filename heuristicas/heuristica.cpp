#include "heuristica.h"
#include "utiles.h"

TEG::Heuristica::Heuristica()
{
}

TEG::Heuristica::~Heuristica(){
}

void TEG::Heuristica::fichas(TEG::TurnoFichas *turno){
    QList<TEG::Pais*> *lista;

    // Distribuir fichas del continente
    int * conts = turno->getFichasContDis();
    for ( int i = 0 ; i < 6 ; i++ ){
        if ( conts[i] > 0 ){
            QList<TEG::Pais*> * paises = turno->ronda->game->mapa->getPaisesContinente(i);
            for ( QList<TEG::Pais*>::iterator i = paises->begin() ; i != paises->end() ; i++ )
                for ( int it = 0 ; it < this->factorFichas(turno,paises,(*i)) ; it++ )
                    lista->append(*i);
            while ( turno->getFichasContDis()[i] > 0 ){
                int pos = TEG::Utiles::getRandom( paises->size() );
                turno->agregarFicha(paises->at(pos));
                lista->removeAt(pos);
            }
            lista->clear();
            paises->clear();
        }
    }

    // Distribuir fichas normales:
    QList<TEG::Pais*> * paises = turno->player->getListPaises();
    for ( QList<TEG::Pais*>::iterator i = paises->begin() ; i != paises->end() ; i++ ){
        for ( int it = 0 ; it < this->factorFichas(turno,paises,*i) ; it++ )
            lista->append(*i);
    }

    // PONER LAS FICHAS :D (TODAS si o si). No olvidarse de repartir en el continente.
    while ( turno->getFichasDisp() > 0 ){
        int pos = TEG::Utiles::getRandom( paises->size() );
        turno->agregarFicha(paises->at(pos));
        paises->removeAt(pos);
    }

    // Eliminar la lista.
    lista->clear();
    delete lista;
}

void TEG::Heuristica::ataque(TEG::TurnoAtaques *turno){
    // Usar get Acciones, y a cada acción aplicar la heurística (de ataque)
    QList<TEG::Accion*> *accs = this->getAcciones(turno,false);
    QList<QPair<TEG::AccionAtaque*,int> > * tabla = new QList<QPair<TEG::AccionAtaque*,int> >();
    for ( QList<TEG::Accion*>::iterator i = accs->begin() ; i != accs->end() ; i++ ){
        QPair<TEG::AccionAtaque*,int> par;
        par.first = (TEG::AccionAtaque*) *i;
        par.second = this->factorAtaque(turno,(TEG::AccionAtaque*) *i);
        tabla->append(par);
    }

    // Ordenar las acciones con qSort y TEG::Heuristica::sortingAcciones
    qSort(tabla->begin(),tabla->end(), TEG::Heuristica::sortingAccion);

    // Pregunto si quiero pasar (next()). Si no:
    TEG::AccionAtaque* accion = tabla->first().first;
    if ( this->next(turno) > tabla->first().second )
        turno->end(); // NEXT!
    else // ejecutar la primera acción
        accion->execute();

    // Borrar todo
    tabla->clear(); // vacío la tabla (no tan necesario)
    for ( QList<TEG::Accion*>::iterator i = accs->begin() ; i != accs->end() ; i++ ) // Borro las acciones (necesario)
        if ( *i != accion ) delete *i;

}

void TEG::Heuristica::reagrupe(TEG::TurnoAtaques *turno){
    // Usar get Acciones, y a cada acción aplicar la heurística (de ataque)
    QList<TEG::Accion*> *accs = this->getAcciones(turno,true);
    QList<QPair<TEG::AccionReagrupe*,int> > * tabla = new QList<QPair<TEG::AccionReagrupe*,int> >();
    for ( QList<TEG::Accion*>::iterator i = accs->begin() ; i != accs->end() ; i++ ){
        QPair<TEG::AccionReagrupe*,int> par;
        par.first = (TEG::AccionReagrupe*) *i;
        par.second = this->factorReagrupe(turno,(TEG::AccionReagrupe*) *i);
        tabla->append(par);
    }

    // Ordenar las acciones con qSort y TEG::Heuristica::sortingAcciones
    qSort(tabla->begin(),tabla->end(), TEG::Heuristica::sortingAccion);

    // Pregunto si quiero pasar (next()). Si no:
    TEG::AccionReagrupe* accion = tabla->first().first;
    if ( this->next(turno) > tabla->first().second )
        turno->end(); // NEXT!
    else // ejecutar la primera acción
        accion->execute();

    // Borrar todo
    tabla->clear(); // vacío la tabla (no tan necesario)
    for ( QList<TEG::Accion*>::iterator i = accs->begin() ; i != accs->end() ; i++ ) // Borro las acciones (necesario)
        if ( *i != accion ) delete *i;
}

QList<TEG::Accion*> *TEG::Heuristica::getAcciones(TEG::TurnoAtaques *turno, bool reagrupe ){
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

float TEG::Heuristica::factorReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc){return 0;}
float TEG::Heuristica::cantidadReagrupe(TEG::TurnoAtaques *turno,TEG::AccionReagrupe *acc){return 0;}
float TEG::Heuristica::factorAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){return 0;}
float TEG::Heuristica::cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){return 0;}
int TEG::Heuristica::factorFichas(TEG::TurnoFichas *turno,QList<TEG::Pais*> *paises, TEG::Pais *pais){return 0;}
int TEG::Heuristica::next(TEG::TurnoAtaques *turno){return false;}


bool TEG::Heuristica::sortingAccion(const QPair<TEG::Accion*,int>& e1, const QPair<TEG::Accion*,int>& e2) { // sorting by QHash Value
    return ( e1.second < e2.second );
}
