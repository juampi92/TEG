#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "mapa.h"
#include "jugador.h"

namespace TEG {
    class Mapa;
    class Game;
    class Jugador;
}
class MainWindow;

class TEG::Game
{
public:
    Game(MainWindow *gui);
    ~Game();

    QStringList getColores(QStringList lista);
    int getCantPlayers() const;
    bool existsPlayerName(QString nom);

    void addPlayer(QString nom, QString color, int IA);

    void start();

    MainWindow *gui;
private:
    TEG::Mapa *mapa;
    QList<TEG::Jugador*> *jugadores;
    QList<TEG::Objetivo*> *objetivos;
};

#endif // GAME_H
