#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

int main();
int zx = 700;
void SMILE (int x, int y, int clr)
{
	setcolor(clr);
    arc    (x, y+20, 180, 360, 50);
    circle (x, y, 100);
    moveto (x, y-25);
    lineto (x, y+25);
    circle (x-40, y-20, 10);
    circle (x+40, y-20, 10);
    circle (x-110, y-30, 15);
    circle (x+110, y-30, 15);
}

int MOVE1 ( int &x, int &y)
{
    while ( (x+100)<zx && (y+100)<zx )
	{
		SMILE (x, y, 4);
		delay(1);
		SMILE (x, y, 0);
		x+=5;
		y+=5;
		if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
    }
    while (( x>100))
    {
    	SMILE (x, y, 4);
    	delay(1);
    	SMILE (x, y, 0);
    	x-=5;
    	if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
	}
}

int MOVE2 (int& x, int& y)
{
    while ( ((x+100)<zx) && ((y-100)>0) )
	{
		SMILE (x, y, 4);
		delay(1);
		SMILE (x, y, 0);
		x+=3;
		y-=3;
		if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
    }
    while ( x>100 )
    {
    	SMILE (x, y, 4);
    	delay(1);
    	SMILE (x, y, 0);
    	x-=3;
    	if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
	}
}

int MOVE3 (int& x, int& y)
{
    while ( ((x-100)>0) && ((y+100)<zx))
	{
		SMILE (x, y, 4);
		delay(1);
		SMILE (x, y, 0);
		x-=3;
		y+=3;
		if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
    }
    while ( x<900)
    {
    	SMILE (x, y, 4);
    	delay(1);
    	SMILE (x, y, 0);
    	x+=3;
    	if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
	}
}

int MOVE4 (int& x, int& y)
{
    while ( ((x-100)<0) && ((y-100)<0) )
	{
		SMILE (x, y, 4);
		delay(1);
		SMILE (x, y, 0);
		x-=3;
		y-=3;
		if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
    }
    while ( x<900 )
    {
    	SMILE (x, y, 4);
    	delay(1);
    	SMILE (x, y, 0);
    	x+=3;
    	if ( kbhit() )
        if ( getch() == 27 ) { closegraph(); main(); }
	}
}

int freemove()
{
	initwindow (zx, zx);
	int x=0;
	int y=0;
	while (1)
	{
	   if ( kbhit() )
       if ( getch() == 27 ) { closegraph(); return 0; }
	   if (x<500)
	   {
		   if (y<500) MOVE1 (x, y);
		   else MOVE2 (x, y);
	   }
	   else
	   {
		   if (y<500) MOVE3 (x, y);
   	   	   else MOVE4 (x, y);
	   }
    }
}

int arrowmove()
{
	initwindow (zx, zx);
	int x=zx/2;
	int y=zx/2;
	while ( 1 )
    {
      int code;
      SMILE (x, y, 3);
      code = getch();
      SMILE (x, y, 0);
      switch (code) 
      {
        case 75:  x=x-15; break;
        case 77:  x=x+15; break;
        case 72:  y=y-15; break;
        case 80:  y=y+15; break;
        case 27: closegraph(); return 0;
      }

    }
}

int main()
{setlocale( LC_ALL, "Russian" );
	int num;
	while (1)
	{
	printf("\n\n1. Свободное движение объекта ");
	printf("\n\n2. Движение объекта с помощью клавиатуры");
	printf("\n\n3. Выход из программы \n");
	scanf("%d",&num);
	switch (num)
	{
		case 1: freemove(); break;
		case 2: arrowmove(); break;
		case 3: return 0; break;
		}
	}
}

