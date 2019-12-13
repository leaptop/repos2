#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <ctime>
#include "point.h"
class Line:public Point
{
	protected:
		int x1,y1;
	public:
		Line(int ax,int ay,int bx,int by,int c,int r):Point(ax,ay,c,r),x1(bx),y1(by){
		};
		Line():Point()
		{
			x1=x+10;
	       	y1=y;
		};	 
		void ShowInfo();
		void Show();
		void Hide();
		void Move();
};

void Line::ShowInfo()
{
	cout<<"("<<x<<","<<x1<<","<<y<<","<<y1<<")"<<endl;
};
void Line::Hide()
{
	setcolor(0);
	line(x,y,x1,y1);
};
void Line::Show()
{
	setcolor(color);
	line(x,y,x1,y1);
};
void Line::Move()
{
	Show();
	delay(10);
	Hide();
	x=x+k;
	x1=x+k;						
	if (x1==600 || x==0)
		k*=-1;
};
