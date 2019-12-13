#include "class.h"
#include <math.h>
#include "const.h"
#define N 0.1

float t = 0; 
float r = 0; 
float s = 0; 
float g = 0; 
float k = 0; 


float figures::getPosX() const{
	return x;
}

void figures::setPosX(const float x){
	figures::x = x;
}

float figures::getPosY() const{
	return y;
}

void figures::setPosY(const float y){
	figures::y = y;
}

int figures::getColor() const{
	return color;
}

void figures::setColor(const int color){
	figures::color = color;
}




void circleClass::move(){
	
	x = x + 15 * cos(t);
	y = y + 15 * sin(t);
	t+= N;
	
}

void circleClass::draw(){
	setcolor(getColor());
	circle(getPosX(), 
		   getPosY(), 10);
}


void rectangleClass::move(){
	
	x = x + 15 * cos(r);
	y = y + 15 * sin(r);
	r+= N;
}

void rectangleClass::draw(){
	setcolor(getColor());
	rectangle(getPosX(), getPosY(),
			  getPosX() + RECTANGLE_SIZE/ 2, 
			  getPosY() + RECTANGLE_SIZE );
}

void triangleClass::move(){
	
	x = x + 15 * cos(s);
	y = y + 15 * sin(s);
	s+= N;
}

void triangleClass::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x - 17, y + 60);
	line(x - 19, y + 60, 
		 x + 19, y + 60);
}

void triangleLeftClass::move(){
	
	x = x + 15 * cos(k);
	y = y + 15 * sin(k);
	k+= N;
}

void triangleLeftClass::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x , y + 60);
	line(x - 1, y + 60, 
		 x + 18, y + 60);
}

void triangleRightClass::move(){
	
	x = x + 15 * cos(g);
	y = y + 15 * sin(g);
	g+= N;
}

void triangleRightClass::draw(){
	setcolor(color);
	line(x, y, x-17 , y + 60);
	line(x, y, x , y + 60);
	line(x - 18, y + 60, 
		 x + 1, y + 60);
}

