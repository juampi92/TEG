#include "game.h"

TEG::Game::Game(MainWindow *gui){
    this->gui = gui;
    this->mapa = new TEG::Mapa(this);
}

TEG::Game::~Game(){
    delete mapa;
}
