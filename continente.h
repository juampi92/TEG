#ifndef CONTINENTE_H
#define CONTINENTE_H

#include <QString>
#include <QList>

#include "pais.h"

namespace TEG{
    class Continente;
    class Pais;
}

class TEG::Continente
{
public:
    Continente(QString nom, int id);
    ~Continente();

    QList<TEG::Pais*> *getPaises();
    void setPaises(QList<TEG::Pais*> *lista);
private:
    int id;
    QString nom;
    QList<TEG::Pais*> *paises;

};

#endif // CONTINENTE_H
