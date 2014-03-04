#include "game.h"
#include "utiles.h"

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

    this->addPlayer("Juan","red",0);
    this->addPlayer("Diego","black",0);
    this->addPlayer("Compu","blue",1);
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

QString TEG::Game::getPaisColor(int id) const{
    return this->mapa->paises[id]->getOwner()->getColor();
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

QList<TEG::Pais*> * TEG::Game::getBorderFriends(int id_pais, TEG::Jugador * player){
    QList<TEG::Pais*> * lim = this->mapa->getLimitrofes(id_pais);
    QList<TEG::Pais*> * retorno = new QList<TEG::Pais*>();

    QList<TEG::Pais*>::iterator i;
    for ( i = lim->begin() ; i != lim->end() ; i++ ){
        if ( (*i)->getOwner()->getID() == player->getID() ) {
            retorno->append((*i));
            this->gui->setPaisFichas((*i)->getID(),2);
        }
    }

    return retorno;
}

QList<TEG::Pais*> * TEG::Game::getBorderEnemies(int id_pais, TEG::Jugador * player){
    QList<TEG::Pais*> * lim = this->mapa->getLimitrofes(id_pais);
    QList<TEG::Pais*> * retorno = new QList<TEG::Pais*>();

    QList<TEG::Pais*>::iterator i;
    for ( i = lim->begin() ; i != lim->end() ; i++ ){
        if ( (*i)->getOwner()->getID() != player->getID() )
            retorno->append((*i));
    }

    return retorno;
}

void TEG::Game::start(){
    this->shufflePaises();
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
        (*i)->addPais(aux);
        this->gui->setPaisColor(aux->getID(),(*i)->getColor());
        this->gui->setPaisFichas(aux->getID(),1);
        i++;
    }
}

QList<int> * TEG::Game::toIntList(QList<TEG::Pais *> *paises){
    QList<int> * retorno = new QList<int>();

    QList<TEG::Pais*>::iterator i;
    for ( i = paises->begin() ; i != paises->end() ; i++ ){
        retorno->append((*i)->getID());
    }

    return retorno;
}




void TEG::Game::pressed(int id){
    this->gui->allEnabled(false);
    this->gui->setPaisesEnabled(this->toIntList(this->getBorderEnemies(id,this->jugadores->at(0))),true);
}
