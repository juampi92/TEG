#ifndef OBJETIVO_H
#define OBJETIVO_H

#include <QString>
#include <QList>

#include "pais.h"

namespace TEG{
    class Objetivo;
}

class TEG::Objetivo
{
public:
    Objetivo(int id, QString descr, int *obj);
    ~Objetivo();

    bool cumplio(const QList<TEG::Pais*> *paises);
    float factor(const QList<TEG::Pais*> *paises);
    int restantes(const QList<TEG::Pais*> *paises);

private:
    int id;
    QString descr;
    int *continentes;

    int *getContArray(const QList<TEG::Pais*> *paises);
};

#endif // OBJETIVO_H
