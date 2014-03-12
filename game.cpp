#include "game.h"
#include "utiles.h"
#include "inteligenciaartificial.h"

#include "turnos/turnoataques.h"
#include "turnos/turnofichas.h"

TEG::Game::Game(MainWindow *gui){
    this->gui = gui;
    this->mapa = new TEG::Mapa(this);
    this->jugadores = new QList<TEG::Jugador*>();
    this->started = false;

    this->objetivos[0]=(new TEG::Objetivo(0,QString("Ocupar África, 5 países de América del Norte y 4 países de Europa."),TEG::Utiles::integerArray(5,0,4,0,6,0)));
    this->objetivos[1]=(new TEG::Objetivo(2,QString("Ocupar Asia y 2 países de América del Sur."),TEG::Utiles::integerArray(0,2,0,15,0,0)));
    this->objetivos[2]=(new TEG::Objetivo(3,QString("Ocupar Europa, 4 países de Asia y 2 países de América de Sur."),TEG::Utiles::integerArray(0,2,9,4,0,0)));
    this->objetivos[3]=(new TEG::Objetivo(4,QString("Ocupar América del Norte, 2 países de Oceanía y 4 de Asia."),TEG::Utiles::integerArray(10,0,0,4,0,2)));
    this->objetivos[4]=(new TEG::Objetivo(5,QString("Ocupar 2 países de Oceanía, 2 países de África, 2 países de América del Sur, 3 países de Europa, 4 de América del Norte y 3 de Asia."),TEG::Utiles::integerArray(4,2,3,3,2,2)));
    this->objetivos[5]=(new TEG::Objetivo(6,QString("Ocupar Oceanía, América del Norte y 2 países de Europa."),TEG::Utiles::integerArray(10,0,2,0,0,4)));
    this->objetivos[6]=(new TEG::Objetivo(7,QString("Ocupar América del Sur, África y 5 países de América del Norte."),TEG::Utiles::integerArray(5,6,0,0,6,0)));

    // Creación automática de jugadores. Propósitos de Test
    this->addPlayer("Juan","red",0);
    this->addPlayer("Diego","black",1);
    this->addPlayer("Compu","blue",1);
}

TEG::Game::~Game(){
    delete mapa;
    // Borrar lista de jugadores con los jugadores
    // Borrar lista de objetivos
}

QStringList TEG::Game::getColores(QStringList lista){
    QStringList colores = lista;

    QList<TEG::Jugador*>::iterator i;
    for (i = this->jugadores->begin(); i != this->jugadores->end(); ++i)
        colores.removeAt( colores.indexOf( (*i)->getColor() ) );

    return colores;
}

int TEG::Game::getCantPlayers(){
    return this->jugadores->size();
}

bool TEG::Game::existsPlayerName(QString nom){
    QList<TEG::Jugador*>::iterator i;
    for (i = this->jugadores->begin(); i != this->jugadores->end(); ++i)
        if ( (*i)->getName() == nom ) return true;
    return false;
}

QString TEG::Game::getPaisColor(int id) const{
    return this->mapa->paises[id]->getOwner()->getColor();
}

void TEG::Game::addPlayer(QString nom, QString color, int IA){
    int id = this->jugadores->size();
    if ( IA == 0 ){
        this->jugadores->append(new TEG::Jugador(this,nom,id,color));
    } else {
        // Agregar IA, pero esto es para test.
        this->jugadores->append(new TEG::InteligenciaArtificial(this,nom,id,color,IA));
    }

    this->gui->addPlayer(nom,color,IA,id);
}

bool TEG::Game::hasStarted() const{
    return this->started;
}

void TEG::Game::start(){
    this->shufflePaises();
    this->shuffleObjetivos();
    // Objetivos y paises repartidos.

    this->started = true;

    this->ronda = new TEG::RondaManager(this,this->jugadores);
    this->ronda->start();
}

void TEG::Game::end(){
    this->started = false;
}

void TEG::Game::shufflePaises(){
    TEG::Pais ** shuffled = TEG::Utiles::shuffle(this->mapa->paises,50);
    TEG::Pais *aux;
    QList<TEG::Jugador*>::iterator i = this->jugadores->begin();

    //for ( int i = 0 ; i < length ; i++ )
    //    qDebug() << aux[i]->getName();

    for ( int j = 0 ; j < 50 ; j++ ) {
        if ( i == this->jugadores->end() ) i = this->jugadores->begin();
        aux = shuffled[j];
        aux->setOwner((*i));
        aux->setEjercitos(1);
        (*i)->addPais(aux);
        this->gui->setPaisColor(aux->getID(),(*i)->getColor());
        this->gui->setPaisFichas(aux->getID(),1);
        i++;
    }
    this->jugadores->size();
}

void TEG::Game::shuffleObjetivos(){
    TEG::Objetivo ** shuffled = TEG::Utiles::shuffle(this->objetivos,7);
    int j = 0;
    QList<TEG::Jugador*>::iterator it;
    for( it = this->jugadores->begin() ; it != this->jugadores->end(); it++){
        (*it)->setObjetivo(shuffled[j]);
        j++;
    }
}



void TEG::Game::pressed(int id){
    if ( this->hasStarted() )
        this->ronda->btnClick(id);
}
