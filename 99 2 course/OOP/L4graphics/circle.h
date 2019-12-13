#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <ctime>
#include "point.h"
class Circle:public Point
{
	protected:
		int rad;
	public:
		Circle(int ax,int bx,int c,int s,int r):Point(ax,bx,c,s),rad(r){
		};
		Circle():Point()
		{
			rad=rand()%40;
		};
		void Show()
		{
			setcolor(color);
			circle(x,y,rad);
		};
		void Hide()
		{
			setcolor(0);
			circle(x,y,rad);
		};
		void Move()
		{
			Show();
			delay(10);
			Hide();
			x=x+k;						
			if (x+rad==600 || x-rad==0)
				k*=-1;
		};
};
