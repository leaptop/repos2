#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <graphics.h>
using namespace std;

class tPoint
{
	private:
		int x,y;//coords
		int color;
	public:
		void set_pos(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		
		void show_pos()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
		
		void input_point()
		{
			cin>>x;
			cin>>y;
		}
		
		void rand_point(int xmax,int ymax)
		{
			
			x=rand()%xmax;
			y=rand()%ymax;
			color=rand()%16+1;
		}
		
		void draw_point()
		{
			putpixel(x,y,color);
		}
		
		void line_move()//linear motion
		{
			int dir=rand()%4;
			int hor,vert;
			switch(dir)
			{
				case 0:
					hor=1;
					break;
				case 1:
					hor=-1;
					break;
				case 2:
					vert=1;
					break;
				case 3:
					vert=-1;
					break;
			}
			while(1)
			{	
	
				putpixel(x,y,color);
				delay(10);
				putpixel(x,y,0);
				if (dir==0 || dir==1)
				{
					x=x+hor;
				}
				else
					y=y+vert;					
				if (x==600 || x==0)
					hor*=-1;
				if (y==600 || y==0)
					vert*=-1;
			}
		}
		
		void rand_move()
		{
			int dir=rand()%4;
			int hor,vert;
			int k,s;
			srand(time(NULL));
			while(1)
			{	
				switch(dir)//deciding wether to change x or y for the next motion
				{
					case 0:
						hor=1;
						break;
					case 1:
						hor=-1;
						break;
					case 2:
						vert=1;
						break;
					case 3:
						vert=-1;
						break;
				}
				
				putpixel(x,y,color);
				delay(10);
				putpixel(x,y,0);
				if (dir==0 || dir==1)
				{
					x=x+hor;					
				}
				else
					y=y+vert;					
				if (x==600 || x==0)
					{
						hor*=-1;
						if (x==600)
						{
							x--;
						}
						else if (x==0)
						{
							x++;
						}
					}
				if (y==600 || y==0)
					{
						vert*=-1;
						if (y==600)
						{
							y--;
						}
						else if (y==0)
						{
							y++;
						}
					}
		
				//k=rand()%1000;
				s=k%11;//cutting chances for changing of direction
				if (s==3)
					dir=rand()%4;//changes every cycle => the dot moves new direction every time 
				
			}
		}
};

