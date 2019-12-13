#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <ctime>
#include "tpo.cpp"

using namespace std;




int main()
{
	srand(time(NULL));
	tPoint arr[100];
	initwindow(600,600);
	for (int i=0;i<100;i++)
	{
		arr[i].rand_point(600,600);
		arr[i].draw_point();
	}

	arr[1].line_move();
	getch();
	
}

