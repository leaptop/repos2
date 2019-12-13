#include "Raquete.h"

Raquete::Raquete(int x, int y) : q(x, y)
{
    ;
}

void Raquete::desenha()
{
    int yatual = q.Gety();
    for(int i = -2; i <= 2; ++i)
    {
        q.Sety(yatual + i);
        q.desenha();
    }
    q.Sety(yatual);
}

void Raquete::moveUp(int limite)
{
    if(q.Gety() > 2 && q.Gety() < limite - 2)
        q.Sety(q.Gety() - 1);
}

void Raquete::moveDown(int limite)
{
    if(q.Gety() > 2 && q.Gety() < limite - 2)
        q.Sety(q.Gety() + 1);
}
