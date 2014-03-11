#ifndef OBJETIVO_H
#define OBJETIVO_H

#include <QString>
#include <QList>

#include "pais.h"

namespace TEG{
    class Objetivo;
    class Pais;
}

class TEG::Objetivo
{
public:
    Objetivo(int id, QString descr, int *obj);
    ~Objetivo();

    QString showObjetivo() const;
    bool cumplio(const QList<TEG::Pais*> *paises);
    bool cumplio(const int *conts);
    float factor(const QList<TEG::Pais*> *paises);
    float factor(const int *conts);
    int restantes(const QList<TEG::Pais*> *paises);
    int restantes(const int *conts);

    bool favorece(int *conts, TEG::Pais* pais);
    int extra(int *conts, TEG::Pais* pais);

    static int *getContArray(const QList<TEG::Pais*> *paises);

private:
    int id;
    int *continentes;
    QString descr;
};

#endif // OBJETIVO_H
