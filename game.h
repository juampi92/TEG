#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "mapa.h"
#include "jugador.h"
#include "objetivo.h"
#include "rondamanager.h"

namespace TEG {
    class Mapa;
    class Game;
    class Jugador;
    class Objetivo;
    class RondaManager;
}
class MainWindow;

class TEG::Game
{
public:
    Game(MainWindow *gui);
    ~Game();

    QStringList getColores(QStringList lista);
    int getCantPlayers();
    bool existsPlayerName(QString nom);

    QString getPaisColor(int id) const;

    void addPlayer(QString nom, QString color, int IA);

    bool hasStarted() const;

    void start();
    void end();

    void shufflePaises();
    void shuffleObjetivos();


    // -------------- TMP
    void pressed(int id);

    MainWindow *gui;
    TEG::Mapa *mapa;
    TEG::RondaManager *ronda;

private:
    QList<TEG::Jugador*> *jugadores;
    TEG::Objetivo *objetivos[7];

    bool started;
};

#endif // GAME_H
