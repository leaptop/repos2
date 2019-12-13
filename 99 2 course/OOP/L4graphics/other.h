#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <ctime>

using namespace std;

class Point
{
	protected:
		int x,y,color,k;
	public:
		Point(int ax,int ay,int col,int kr):x(ax),y(ay),color(col),k(kr){
		};
		Point()
		{
			srand(time(NULL));
	       	x=10;
	       	y=10;
	       	color=10;
	       	k=5;
		};
		void ShowInfo()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		};
		void Show()
		{
			putpixel(x,y,color);
		};
		void Hide()
		{
			putpixel(x,y,0);
		};
		void Move()
		{
			Show();
						delay(6);
			Hide();

			x=x+k;						
			if (x==600 || x==0)
				k*=-1;
		};
};


class Line:public Point
{
	protected:
		int x1,y1;
	public:
		Line(int ax,int ay,int col,int kr,int bx,int by):Point(ax,ay,col,kr),x1(bx),y1(by){
		};
		Line():Point()
		{
			x1=x+60;
			y1=y;
		};
		void Show()
		{
			setcolor(color);
			line(x,y,x1,y1);
		};
		void Hide()
		{
			setcolor(0);
			line(x,y,x1,y1);
		};
		void Move()
		{
			Show();
			delay(1);
			Hide();
			x=x+k;	
			x1=x1+k;					
			if (x1==600 || x==0)
				k*=-1;
		};
};


class Circle:public Point
{
	protected:
		int rad;
	public:
		Circle(int ax,int ay,int col,int kr,int r):Point(ax,ay,col,kr),rad(r){
		};
		Circle():Point()
		{
			rad=40;
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
			delay(6);
			Hide();
			x=x+k;						
			if (x+rad==600 || x-rad==0)
				k*=-1;
		};
};

class Elipse:public Circle
{
	protected:
		int radi2;
	public:
		Elipse(int ax,int ay,int col,int kr,int r,int r2):Circle(ax,ay,col,kr,r),radi2(r2){
		};
		Elipse():Circle()
		{
			radi2=20;
		};
		void Show()
		{
			setcolor(color);
			ellipse(x,y,0,360,rad,radi2);
		};
		void Hide()
		{
			setcolor(0);
			ellipse(x,y,0,360,rad,radi2);
		};
		void Move()
		{
			Show();
			delay(6);
			Hide();
			x=x+k;						
			if (x+rad==600 || x-rad==0)
				k*=-1;
		};
};

class Rect:public Line
{
	public:
		Rect(int ax,int ay,int col,int kr,int bx,int by):Line(ax,ay,col,kr,bx,by){
		};
		Rect():Line()
		{
			x1=x+60;
			y1=y+20;
		};
		void Show()
		{
			setcolor(color);
			rectangle(x,y,x1,y1);
		};
		void Hide()
		{
			setcolor(0);
			rectangle(x,y,x1,y1);
		};
		void Move()
		{
			Show();
			delay(6);
			Hide();
			x=x+k;
			x1+=k;						
			if (x1==600 || x==0)
				k*=-1;
		};
};

class Trian:public Rect
{
	protected:
		int x2,y2;
	public:
		Trian(int ax,int ay,int col,int kr,int bx,int by,int sx,int sy):Rect(ax,ay,col,kr,bx,by),x2(sx),y2(sy){
		};
		Trian():Rect()
		{
			x2=rand()%100;
			y2=rand()%100;
		};
		void Show()
		{
			setcolor(color);
			line(x,y,x1,y1);
			line(x,y,x2,y2);
			line(x1,y1,x2,y2);
		};
		void Hide()
		{
			setcolor(0);
			line(x,y,x1,y1);
			line(x,y,x2,y2);
			line(x1,y1,x2,y2);
		};
		void Move()
		{
			Show();
			delay(6);
			Hide();
			x=x+k;
			x1+=k;
			x2+=k;						
			if (x1==0 || x2==0 || x==0)
				k*=-1;
			if (x1==600 || x2==600 || x==600)
				k*=-1;
		};
};


