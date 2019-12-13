#include <iostream>
#include <time.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "other.h"

int main()
{
	initwindow(600,600);
	//Line* B;
	//B=new Line;
	Line b(10,30,10,5,40,30);
	Point a(10,300,10,5);
	Circle c(60,120,10,1,10);//x, y, color, pause, radius
	Elipse d(60,170,10,5,50,30);
	Rect e(60,260,10,5,150,300);
	Trian f(60,330,10,5,150,350,80,390);
	while(1)
	{
		e.Move();
	}

	getch();
}
