#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "mapa.h"

namespace TEG {
    class Mapa;
    class Game;
}
class MainWindow;

class TEG::Game
{
public:
    Game(MainWindow *gui);
    ~Game();

    MainWindow *gui;

private:
    TEG::Mapa *mapa;
};

#endif // GAME_H
