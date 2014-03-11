#ifndef ACCIONATAQUE_H
#define ACCIONATAQUE_H

#include "accion.h"

namespace TEG{
    class AccionAtaque;
}

class TEG::AccionAtaque : public TEG::Accion
{
public:
    AccionAtaque(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game);
    ~AccionAtaque();

    bool validar();
    void calcularFichas();
    void execute();

    float prob();
    int getMax();

    bool endAnimacion();
private:
    bool win;
    struct {
        int orig;
        int dest;
    } fichas;
};

#endif // ACCIONATAQUE_H
