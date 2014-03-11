#include "turnofichas.h"
#include "utiles.h"

TEG::TurnoFichas::TurnoFichas(TEG::RondaManager *ronda, TEG::Jugador *plyr, int spec) : TEG::Turno(ronda,plyr){
    this->fichasDisp = 0;
    this->contFichas_total = 0;

    if ( spec > 0 )
        this->fichasDisp = spec;
    else {
        this->fichasDisp = this->calcularFichas();
        this->createContsArray();
    }
}

TEG::TurnoFichas::~TurnoFichas(){

}

void TEG::TurnoFichas::play(){
    TEG::Turno::play();
    this->startTurno();
}

void TEG::TurnoFichas::paisClick(int id){
    this->agregarFicha(this->ronda->game->mapa->getPais(id));
}

void TEG::TurnoFichas::agregarFicha(TEG::Pais *pais){
    // Validación:
    if ( pais->getOwner()->getID() != this->player->getID() )
        return; // No es tu país

    // Descontar ficha:
    if ( this->contFichas_total > 0 && this->contsFichas[pais->getContinenteID()] > 0 ){
        this->contsFichas[pais->getContinenteID()]--;
        this->contFichas_total--;
    } else if ( this->fichasDisp > 0 ) {
        this->fichasDisp--;
    } else return;

    // Gui
    this->ronda->game->gui->setPaisFichas(pais->getID(),pais->addEjercitos(1));

    this->ronda->game->gui->setPlayerInfo("",-1,this->player->getCantEjercitos(),this->getFichasDisp());

    if ( this->fichasDisp == 0 && this->contFichas_total == 0 ) this->end();
}

int TEG::TurnoFichas::getFichasDisp(){
    return this->fichasDisp + this->contFichas_total;
}

void TEG::TurnoFichas::startTurno(){
    this->player->playFichas(this);
}

int TEG::TurnoFichas::calcularFichas(){
    int f = this->player->getCantPaises() / 2;
    if ( f < 3 ) f = 3; // Minimo.
    return f;
}

void TEG::TurnoFichas::createContsArray(){
    int * totales = this->ronda->game->mapa->paises_por_continente;
    int * posee = this->player->getContArray();
    this->contsFichas = TEG::Utiles::integerArray(0,0,0,0,0,0);

    int aux;
    for ( int i = 0 ; i < 6 ; i++ )
        if ( totales[i] == posee[i] ) { aux = totales[i]/2; contsFichas[i]=aux; contFichas_total+=aux; }

    qDebug() << "Fichas de continente: " << contFichas_total;
}
