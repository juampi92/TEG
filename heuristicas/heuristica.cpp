#include "heuristica.h"
#include "utiles.h"

TEG::Heuristica::Heuristica()
{
}

TEG::Heuristica::~Heuristica(){
}

void TEG::Heuristica::fichas(TEG::TurnoFichas *turno){
    QList<TEG::Pais*> *lista= new QList<TEG::Pais*>;

    // Distribuir fichas del continente
    int * conts = turno->getFichasContDis();
    for ( int i = 0 ; i < 6 ; i++ ){
        if ( conts[i] > 0 ){
            QList<TEG::Pais*> * paises = turno->ronda->game->mapa->getPaisesContinente(i);
            for ( QList<TEG::Pais*>::iterator it = paises->begin() ; it != paises->end() ; it++ )
                for ( int j = 0 ; j < this->factorFichas(turno,(*it)) ; j++ )
                    lista->append(*it);
            while ( turno->getFichasContDis()[i] > 0 ){
                int pos = TEG::Utiles::getRandom( lista->size() );
                turno->agregarFicha(lista->at(pos));
            }
            lista->clear();
        }
    }


    // Distribuir fichas normales:
    QList<TEG::Pais*> * paises = turno->player->getListPaises(false);
    for ( QList<TEG::Pais*>::iterator it = paises->begin() ; it != paises->end() ; it++ ){
        int numero_de_veces = this->factorFichas(turno,(*it));
        qDebug() << (*it)->getName() << "valor: "<< numero_de_veces;
        for ( int j = 0 ; j < numero_de_veces ; j++ ){
            lista->append(*it);
        }
    }

    // PONER LAS FICHAS :D (TODAS si o si). No olvidarse de repartir en el continente.
    while ( turno->getFichasDisp() > 0 ){
        int pos = TEG::Utiles::getRandom( lista->size() );
        turno->agregarFicha(lista->at(pos));
    }

    // Eliminar la lista.
    lista->clear();
    delete lista;
}

void TEG::Heuristica::ataque(TEG::TurnoAtaques *turno){
    // Usar get Acciones, y a cada acción aplicar la heurística (de ataque)
    QList<TEG::Accion*> *accs = this->getAcciones(turno,false);
    QList<QPair<TEG::AccionAtaque*,int> > * tabla = new QList<QPair<TEG::AccionAtaque*,int> >();
    for ( QList<TEG::Accion*>::iterator it = accs->begin() ; it != accs->end() ; it++ ){
        QPair<TEG::AccionAtaque*,int> par;
        par.first = (TEG::AccionAtaque*) *it;
        par.second = this->factorAtaque(turno,(TEG::AccionAtaque*) *it);
        tabla->append(par);
    }

    // Ordenar las acciones con qSort y TEG::Heuristica::sortingAcciones
    //qSort(tabla->begin(),tabla->end(), TEG::Heuristica::sortingAccion);
    int max = -1000;
    TEG::AccionAtaque* accion= tabla->first().first;
    for( QList<QPair<TEG::AccionAtaque*,int> >::iterator it = tabla->begin() ; it != tabla->end() ; it++ ){
        if((*it).second > max){
            max = (*it).second;
            accion = (*it).first;
        }
    }
    // Pregunto si quiero pasar (next()). Si no:

//    if ( this->next(turno,accion->getOrigen()) > max )
    if (0 > max )

        turno->end(); // NEXT!
    else{
        qDebug() << "entra " ;
        accion->execute();
    }

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
    //qSort(tabla->begin(),tabla->end(), TEG::Heuristica::sortingAccion);

    // Pregunto si quiero pasar (next()). Si no:
    TEG::AccionReagrupe* accion = tabla->first().first;
    if ( this->next(turno,accion->getOrigen()) > tabla->first().second )
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

float TEG::Heuristica::factorAtaque(TEG::TurnoAtaques *turno, TEG::AccionAtaque *acc){
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

float TEG::Heuristica::cantidadAtaque(TEG::TurnoAtaques *turno,TEG::AccionAtaque *acc){return 0;}

int TEG::Heuristica::factorFichas(TEG::TurnoFichas *turno, TEG::Pais *pais){
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

int TEG::Heuristica::next(TEG::TurnoAtaques *turno, TEG::Pais * pais){
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

bool TEG::Heuristica::sortingAccion(const QPair<TEG::Accion*,int>& e1, const QPair<TEG::Accion*,int>& e2) { // sorting by QHash Value
    return ( e1.second < e2.second );
}
