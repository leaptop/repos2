#ifndef RAQUETE_H_INCLUDED
#define RAQUETE_H_INCLUDED

#include "quadrado.h"
#include "fig.h"

class Raquete
{
public:
    Raquete(int, int);
    void desenha();
    void moveUp(int);
    void moveDown(int);
    int getX() {return q.Getx();};
    int getY() {return q.Gety();};
    void setY(int y){q.Sety(y);};

private:
    quadrado q;
};

#endif // RAQUETE_H_INCLUDED
