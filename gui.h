#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <qDebug>
#include <QList>
#include <QMainWindow>
#include "guifichas.h"

#include "ui_mainwindow.h"

namespace TEG {
    class GUI;
    class GUIFichas;
}

class TEG::GUI
{
    public:
        GUI(QGraphicsScene *tablero);
        ~GUI();

        void addPais(int id, int x, int y);
        void setPaisColor(int id, QString color);
        void setPaisFichas(int id, int cant);
        void setPaisEnabled(int id, bool enabled);

        void buttonSelect(int id);

        void setDados(QList<int> atac, QList<int> def);

        void consoleLog(QString msj);

        void callback();
    private:
        QGraphicsScene *board;
        TEG::GUIFichas *paises;

        //Game *game;


};

#endif // GUI_H
