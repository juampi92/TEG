#ifndef TURNOATAQUES_H
#define TURNOATAQUES_H

#include "turno.h"

namespace TEG{
    class TurnoAtaques;
}

class TEG::TurnoAtaques : public TEG::Turno
{
public:
    TurnoAtaques();

    int getInt();
};

#endif // TURNOATAQUES_H
