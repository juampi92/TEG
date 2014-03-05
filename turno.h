#ifndef TURNO_H
#define TURNO_H

namespace TEG{
    class Turno;
}

class TEG::Turno
{
public:
    Turno();

    //A reemplazar
    virtual int getInt();
};

#endif // TURNO_H
