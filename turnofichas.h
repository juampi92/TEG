#ifndef TURNOFICHAS_H
#define TURNOFICHAS_H

#include "turno.h"

namespace TEG{
    class TurnoFichas;
}

class TEG::TurnoFichas : public TEG::Turno
{
public:
    TurnoFichas();

    int getInt();
};

#endif // TURNOFICHAS_H
