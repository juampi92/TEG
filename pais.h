#ifndef PAIS_H
#define PAIS_H

#include <QString>

#include "jugador.h"

namespace TEG {
    class Pais;
    class Jugador;
}

class TEG::Pais
{
public:
    Pais(int id, QString nom, int cont);
    ~Pais();

    bool continenteIgual(int cont);

    int getEjercitos();
    int addEjercitos(int cant);
    int removeEjercitos(int cant);
    int setEjercitos(int cant);
    void setOwner(TEG::Jugador *player);

    int getContinenteID() const;
    int getID() const;
    TEG::Jugador * getOwner() const;
    QString getName() const;

private:
    int id;
    QString nom;
    TEG::Jugador *owner;
    int ejercitos;
    int cont_id;
};

#endif // PAIS_H
