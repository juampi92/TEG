#include "rondamanager.h"

#include "turnos/turnoataques.h"
#include "turnos/turnofichas.h"

TEG::RondaManager::RondaManager(TEG::Game *juego, QList<TEG::Jugador *> *players){
    this->game = juego;
    this->players = players;
    this->actual = this->inicio = players->begin();
    this->special = 2;
    this->turno = 0;
}

TEG::RondaManager::~RondaManager(){
    this->game->gui->nextButton("");
    this->game->end();
}

void TEG::RondaManager::start(){
    this->setType(0);
    this->playTurno();
}

void TEG::RondaManager::end(bool winner){
    if ( winner )
        this->game->gui->setWinner((*this->actual)->getName() , (*this->actual)->getColor() , (*this->actual)->showObjetivo());

    delete this;
}

void TEG::RondaManager::nextTurno(){
    // Check winner
    if ( this->type == 1 && (*this->actual)->gano() ){ this->end(true); return; }

    this->actual++;
    if ( this->actual == this->players->end() )
        this->actual = this->players->begin();

    if ( this->actual == this->inicio ) // Vuelvo al inicio
        this->nextRonda();
    else
        this->playTurno();

}
void TEG::RondaManager::nextRonda(){
    if ( this->special > 1 ){ // Rondas especiales
        this->special--;
    } else {
        this->special = 0;
        int newType;
        if ( this->type == 0 ) newType = 1; else newType = 0;
        this->setType(newType);

        if ( newType == 0 )
            this->desplazarOrden();
    }
    this->actual = this->inicio;
    this->playTurno();
}

void TEG::RondaManager::desplazarOrden(){
    this->inicio++;
    if ( this->inicio == this->players->end() ) this->inicio = this->players->begin();
}

void TEG::RondaManager::playTurno(){
    if ( this->turno != NULL ) delete this->turno;

    if ( this->type == 0 ){

        int fichas = 0;
        if ( this->special == 2 ) fichas=5;
        else if ( this->special == 1 ) fichas=3;

        this->turno = new TEG::TurnoFichas(this,*this->actual,fichas);
    }else if ( this->type == 1 )
        this->turno = new TEG::TurnoAtaques(this,*this->actual);

    this->turno->play();
}

QString TEG::RondaManager::showObjetivo() const{
    return (*actual)->showObjetivo();
}

void TEG::RondaManager::setType(int t){
    this->type = t;
    this->game->gui->setRoundType(t);
}

void TEG::RondaManager::btnClick(int id){
    if ( this->turno == NULL ) return;
    // Valida si es un Bot. Si es un bot, no podés intervenir en el tablero.
    this->turno->paisClick(id);
}

void TEG::RondaManager::btnNext(){
    if ( this->turno->next() ) this->nextTurno();
}
