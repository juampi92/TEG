#ifndef TURNOFICHAS_H
#define TURNOFICHAS_H

#include "turno.h"

namespace TEG{
    class TurnoFichas;
}

class TEG::TurnoFichas : public TEG::Turno
{
public:
    TurnoFichas(TEG::RondaManager *ronda, TEG::Jugador *plyr, int spec=0);
    ~TurnoFichas();

    void play();
    void paisClick(int id);
    int getFichasDisp();
    int *getFichasContDis();

    void agregarFicha(TEG::Pais *pais);

private:
    void startTurno();
    int calcularFichas();
    void createContsArray();

    int fichasDisp;
    int contFichas_total;
    int * contsFichas;
};

#endif // TURNOFICHAS_H
