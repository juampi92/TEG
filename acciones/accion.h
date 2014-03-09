#ifndef TEG_ACCION_H
#define TEG_ACCION_H

#include "../game.h"
#include "../pais.h"

namespace TEG {
    class Accion;
}
class TEG::Accion
{
public:
    Accion(TEG::Pais *origen, TEG::Pais *destino, TEG::Game *game);
    virtual ~Accion();

    virtual bool validar();
    virtual void execute();

    virtual float prob();
    virtual int getMax();

    virtual bool endAnimacion();

    TEG::Pais * getOrigen();
    TEG::Pais * getDestino();

protected:
    TEG::Game *game;
    TEG::Pais *origen;
    TEG::Pais *destino;
};

#endif // TEG_ACCION_H
