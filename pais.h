#ifndef PAIS_H
#define PAIS_H

#include <QString>

namespace TEG {
    class Pais;
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

    int getContinenteID() const;

private:
    int id;
    QString nom;
    //TEG::Player *owner;
    int ejercitos;
    int cont_id;
};

#endif // PAIS_H
