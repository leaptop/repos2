#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <ctime>

class Elipse:public Circle
{
	protected:
		int radius2;
	public:
		Elipse(int ax,int bx,int c,int s,int r,int r2):Circle(ax,bx,c,s,r),radius2(r2){
		};
		Elipse():Circle()
		{
			radius2=20;
		};
		void Show()
		{
			setcolor(color);
			ellipse(x,y,0,360,rad,rad2);
		};
		void Hide()
		{
			setcolor(0);
			ellipse(x,y,0,360,rad,rad2);
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
