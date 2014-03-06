#include "mainwindow.h"
#include <QApplication>
#include <QTime>

#include <QGraphicsView>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    QApplication a(argc, argv);

    QDesktopWidget wid;

    QGraphicsView *gv = new QGraphicsView();
    gv->setGeometry(QRect(
                        ( wid.screen()->width() - 300) / 2,
                        ( wid.screen()->height() - 300) / 2,
                        300,300));
    gv->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    gv->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    gv->setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint);

    QGraphicsScene * scene = new QGraphicsScene();
    gv->setScene(scene);
    scene->addPixmap(QPixmap("presentacion.jpg"));

    gv->show();


    MainWindow w(gv);

    return a.exec();
}
