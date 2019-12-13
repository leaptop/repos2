#include <iostream>
#include "Raquete.h"
#include "windows.h"
#include <conio.h>
using namespace std;

#define TELAX 100
#define TELAY 40
#define SPEED 30
#define KEY_UP 72
#define KEY_DOWN 80
#define W 17
#define S 31
#define ESC 27

void ballMove(quadrado &q, int dirX, int dirY)
{
    q.Setx(q.Getx() + dirX);
    q.Sety(q.Gety() + dirY);

}

bool movementCalculation(quadrado &q, int &dirX, int &dirY, Raquete &r1, Raquete &r2)
{
    if(q.Getx() == 0 || q.Getx() == TELAX)
    {
        return false;
    }
    if(q.Gety() == 0 || q.Gety() == TELAY)
    {
        dirY = -dirY;
    }
    //cout << q.Gety() << r2.getY()
    if((q.Getx() == r1.getX() || q.Getx() == r2.getX()) && ((q.Gety() > r2.getY() - 4 && q.Gety() < r2.getY()+4) || (q.Gety() > r1.getY() - 4 && q.Gety() < r1.getY()+4)))
    {
        dirX = -dirX;
    }

    return true;
}

void moverRaquete1(Raquete &r1)
{
    if(kbhit() == 0) return;
    int c = 0;
    switch((c=_getch())) {
    case KEY_UP:
        r1.setY(r1.getY()-1);
        break;
    case KEY_DOWN:
        r1.setY(r1.getY()+1);
        break;
    }
}

/*void moverRaquete2(Raquete &r2)
{
    if(kbhit() == 0) return;
    int c = 0;
    switch((c=_getch())) {
    case KEY_UP:
        r2.setY(r2.getY()-1);
        break;
    case KEY_DOWN:
        r2.setY(r2.getY()+1);
        break;
    }
}*/

int main()
{
    //cout << "Hello world!" << endl;
    Raquete r(5, 20);
    Raquete r2(95, 20);
    quadrado bola(50, 20);
    int dirX = 1;
    int dirY = 1;
    while(movementCalculation(bola, dirX, dirY, r, r2))
    {
        COORD pos = {TELAX, TELAY};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
        r.desenha();
        r2.desenha();
        bola.desenha();
        //r2.moveDown(TELAY);
        ballMove(bola, dirX, dirY);
        moverRaquete1(r);
        //moverRaquete2(r2);
        Sleep(SPEED);
        system("CLS");
    }
    return 0;
}
