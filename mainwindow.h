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
    void setPaisFichas(int id, int cant);
    void setPaisEnabled(int id, bool enabled);

    void setDados(QList<int> atac, QList<int> def);

    void allEnabled(bool enabled);

    void consoleLog(QString msj);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *board;
    QButtonGroup *paises;
    TEG::Game *game;

    void setUpConnections();

public slots:
    void buttonSelect(int id);

private slots:
    void callback();
};

#endif // MAINWINDOW_H
