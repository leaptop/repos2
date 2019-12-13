#include "classes.h"
#include <math.h>
#include "constants.h"
#define N 0.09

float t = 0; 
float r = 0; 
float s = 0; 
float g = 0; 
float k = 0; 


float shape::getXpos() const{
	return x;
}

void shape::setXpos(const float x){
	shape::x = x;
}

float shape::getYpos() const{
	return y;
}

void shape::setYpos(const float y){
	shape::y = y;
}

int shape::getClr() const{
	return color;
}

void shape::setClr(const int color){
	shape::color = color;
}




void circleCls::move(){
	
	x = x + 15 * cos(t);
	y = y + 15 * sin(t);
	t+= N;
	
}

void circleCls::draw(){
	setcolor(getClr());
	circle(getXpos(), 
		   getYpos(), CIRCLE_RADIUS);
}


void rectangleCls::move(){
	
	x = x + 15 * cos(r);
	y = y + 15 * sin(r);
	r+= N;
}

void rectangleCls::draw(){
	setcolor(getClr());
	rectangle(getXpos(), getYpos(),
			  getXpos() + RECTAN_SIZE/ 2, 
			  getYpos() + 130 );
}

void triangleCls::move(){
	
	x = x + 15 * cos(s);
	y = y + 15 * sin(s);
	s+= N;
}

void triangleCls::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x - 17, y + 60);
	line(x - 19, y + 60, 
		 x + 19, y + 60);
}

void triangLCls::move(){
	
	x = x + 15 * cos(k);
	y = y + 15 * sin(k);
	k+= N;
}

void triangLCls::draw(){
	setcolor(color);
	line(x, y, x + 17, y + 60);
	line(x, y, x , y + 60);
	line(x - 1, y + 60, 
		 x + 18, y + 60);
}

void trianRCls::move(){
	
	x = x + 15 * cos(g);
	y = y + 15 * sin(g);
	g+= N;
}

void trianRCls::draw(){
	setcolor(color);
	line(x, y, x-17 , y + 60);
	line(x, y, x , y + 60);
	line(x - 18, y + 60, 
		 x + 1, y + 60);
}

