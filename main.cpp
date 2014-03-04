#include "mainwindow.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
