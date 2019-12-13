#include "quadrado.h"
#include "windows.h"
#include "stdio.h"

quadrado::quadrado(int x, int y):fig(x,y)
{

    Setid(254);
    //ctor
}

quadrado::~quadrado()
{
    //dtor
}

void quadrado::desenha()
{
    COORD pos = {Getx(), Gety()};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    printf("%c",Getid());
}
