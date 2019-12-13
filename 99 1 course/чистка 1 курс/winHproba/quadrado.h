#ifndef QUADRADO_H
#define QUADRADO_H

#include "fig.h"

class quadrado : public fig
{
    public:
        quadrado(int x, int y);
        virtual ~quadrado();
        virtual void desenha();

    protected:

    private:
};

#endif // QUADRADO_H
