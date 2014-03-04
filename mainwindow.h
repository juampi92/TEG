#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <qDebug>
#include <QList>
#include <QMainWindow>
#include <QButtonGroup>

#include "game.h"

namespace Ui {
    class MainWindow;
}
namespace TEG {
    class Game;
    class GUIFichas;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPais(int id, QString nom, int x, int y);

    void setPaisColor(int id, QString color);
    //void setPaisesColor(QList<int> *paises, QString color);

    void setPaisFichas(int id, int cant);
    void setPaisesFichas(QList<int> *paises, int cant);

    void setPaisEnabled(int id, bool enabled);
    void setPaisEnabled(QAbstractButton * btn, bool enabled);
    void setPaisesEnabled(QList<int> *paises, bool enabled); // Activa los paises pasados por la lista

    void setDados(QList<int> atac, QList<int> def);

    void allEnabled(bool enabled);

    void consoleLog(QString msj);

    void addPlayer(QString nom, QString color, int IA, int id);

    QStringList getColores();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *board;
    QButtonGroup *paises;
    TEG::Game *game;

    void setUpConnections();

public slots: // Botones accesibles desde afuera
    void buttonSelect(int id);

private slots: // Botones internos
    void popupCreatePlayer(); // Crea el formulario para agregar un nuevo jugador.
    void start(); // Comienza el juego.
};

#endif // MAINWINDOW_H
