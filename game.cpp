#include "game.h"

TEG::Game::Game(MainWindow *gui){
    this->gui = gui;
    this->mapa = new TEG::Mapa(this);
    this->jugadores = new QList<TEG::Jugador*>();
    this->objetivos = new QList<TEG::Objetivo*>();


    int* a;
    a = new int[6] {5,0,4,0,6,0};
    this->objetivos->append(new TEG::Objetivo(0,QString("Ocupar África, 5 países de América del Norte y 4 países de Europa."),a));
    a = new int[6] {0,2,0,15,0,0};
    this->objetivos->append(new TEG::Objetivo(2,QString("Ocupar Asia y 2 países de América del Sur."),a));
    a = new int[6] {0,2,9,4,0,0};
    this->objetivos->append(new TEG::Objetivo(3,QString("Ocupar Europa, 4 países de Asia y 2 países de América de Sur."),a));
    a = new int[6] {10,0,0,4,0,2};
    this->objetivos->append(new TEG::Objetivo(4,QString("Ocupar América del Norte, 2 países de Oceanía y 4 de Asia."),a));
    a = new int[6] {4,2,3,3,2,2};
    this->objetivos->append(new TEG::Objetivo(5,QString("Ocupar 2 países de Oceanía, 2 países de África, 2 países de América del Sur, 3 países de Europa, 4 de América del Norte y 3 de Asia."),a));
    a = new int[6] {10,0,2,0,0,4};
    this->objetivos->append(new TEG::Objetivo(6,QString("Ocupar Oceanía, América del Norte y 2 países de Europa."),a));
    a = new int[6] {5,6,0,0,6,0};
    this->objetivos->append(new TEG::Objetivo(7,QString("Ocupar América del Sur, África y 5 países de América del Norte."),a));
}

TEG::Game::~Game(){
    delete mapa;
}

QStringList TEG::Game::getColores(QStringList lista){
    QStringList colores = lista;

    QList<TEG::Jugador*>::iterator i;
    for (i = this->jugadores->begin(); i != this->jugadores->end(); ++i)
        colores.removeAt( colores.indexOf( (*i)->getColor() ) );

    return colores;
}
int TEG::Game::getCantPlayers() const{
    return this->jugadores->size();
}
bool TEG::Game::existsPlayerName(QString nom){
    QList<TEG::Jugador*>::iterator i;
    for (i = this->jugadores->begin(); i != this->jugadores->end(); ++i)
        if ( (*i)->getName() == nom ) return true;
    return false;
}

void TEG::Game::addPlayer(QString nom, QString color, int IA){
    int id = jugadores->size();
    if ( IA == 0 ){
        jugadores->append(new TEG::Jugador(this,nom,id,color));
    } else {
        // Agregar IA, pero esto es para test.
        jugadores->append(new TEG::Jugador(this,nom,id,color));
    }

    this->gui->addPlayer(nom,color,IA,id);
}

void TEG::Game::start(){

}
