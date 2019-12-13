#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <ctime>

using namespace std;

class Point
{
	protected:
		int x,y,rad,color,k;
	public:
		Point(int ax,int ay,int col,int kr):x(ax),y(ay),color(col),k(kr){
		};
		Point()
		{
			srand(time(NULL));
	       	x=rand()%getmaxx();
	       	y=rand()%getmaxy();
	       	color=rand()%getmaxcolor();
	       	k=1;
		};
		void ShowInfo();
		void Show();
		void Hide();
		void Move();
};

void Point::ShowInfo()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
};
void Point::Hide()
{
	putpixel(x,y,0);
};
void Point::Show()
{
	putpixel(x,y,color);
};
void Point::Move()
{
	Show();
	delay(10);
	Hide();
	x=x+k;						
	if (x==600 || x==0)
		k*=-1;
};
