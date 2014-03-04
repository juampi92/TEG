#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "mapa.h"
#include "jugador.h"
#include "objetivo.h"

namespace TEG {
    class Mapa;
    class Game;
    class Jugador;
    class Objetivo;
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

    QString getPaisColor(int id) const;

    void addPlayer(QString nom, QString color, int IA);

    QList<TEG::Pais*> * getBorderFriends(int id_pais, TEG::Jugador * player);
    QList<TEG::Pais*> * getBorderEnemies(int id_pais, TEG::Jugador * player);

    void start();
    void shufflePaises();
    void shuffleObjetivos();


    // -------------- TMP
    void pressed(int id);

    MainWindow *gui;
private:

    QList<int> * toIntList(QList<TEG::Pais*> *paises);

    TEG::Mapa *mapa;
    QList<TEG::Jugador*> *jugadores;
    QList<TEG::Objetivo*> *objetivos;
};

#endif // GAME_H
