#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <qDebug>
#include <QList>
#include <QMainWindow>
#include <QButtonGroup>
#include <QListWidget>
#include <QTimer>

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
    explicit MainWindow(QGraphicsView *pres);
    ~MainWindow();

    void addPais(int id, QString nom, int x, int y);

    void setPaisColor(int id, QString color);
    //void setPaisesColor(QList<int> *paises, QString color);

    void setPaisFichas(int id, int cant);
    void setPaisesFichas(QList<int> *paises, int cant);

    void setPaisEnabled(int id, bool enabled);
    void setPaisEnabled(QAbstractButton * btn, bool enabled);
    void setPaisesEnabled(QList<int> *paises, bool enabled); // Activa los paises pasados por la lista

    void setPaisSelected(int id, bool selected);

    void setDados(QList<int> atac, QList<int> def, bool animacion=true);
    void agregarDado(QGraphicsScene *widget, int dado , int pos );
    void vaciarDados( QGraphicsScene * widget );

    void allEnabled(bool enabled);

    void consoleLog(QString msj);

    void addPlayer(QString nom, QString color, int IA, int id);
    void setTurno(int id , int cant);

    void setPlayerInfo(QString nom, int paises, int ej, int ej_rest);

    QStringList getColores();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *board;
    QButtonGroup *paises;
    TEG::Game *game;

    void setUpConnections();

    void drawDados(QList<int> atac, QList<int> def);

    // Files cache
    QIcon *img_pc;
    QImage *img_dados;
    QPixmap *arr_dados[6]; // Arreglo de punteros a imagen
    //
    struct AnimacionData {
        int loops = 5;
        int loop;
        QList<int> atac;
        QList<int> def;
        QTimer *timer;
    } animacion;

public slots: // Botones accesibles desde afuera
    void buttonSelect(int id);

private slots: // Botones internos
    void dadosUpdate(); // Crear animación de los dados
    void verObjetivo(); //Pop up del objetivo
    void popupCreatePlayer(); // Crea el formulario para agregar un nuevo jugador.
    void start(); // Comienza el juego.
};

#endif // MAINWINDOW_H
