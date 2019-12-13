#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include "constants.h"

class shape
{
public:
	float getXpos() const;
    void setXpos(const float x);
	
	float getYpos() const;
    void setYpos(const float y);	
    
    int getClr() const;
    void setClr(const int color);	
    	
    
    
    virtual void move() = 0;
	virtual void draw() = 0;
    
    shape(){}
    
protected:
	float x;
	float y;
	int color;
};



class circleCls : public shape
{
public:
	void move();
	void draw();
	
	circleCls(float x, float y, int color):shape(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class triangleCls : public shape
{
public:
	void move();
    void draw();
	
	triangleCls(float x, float y, int color):shape(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class triangLCls : public shape
{
public:
	void move();
    void draw();
	
	triangLCls(float x, float y, int color):shape(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class trianRCls : public shape
{
public:
	void move();
    void draw();
	
	trianRCls(float x, float y, int color):shape(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
};

class rectangleCls : public shape
{
public:
	void move();
	void draw();
	int pl;
	
	rectangleCls(float x, float y, int color):shape(){
		setXpos(x);
		setYpos(y);
		setClr(color);
	}
	rectangleCls(void) : pl(300){
	}
};


#endif
