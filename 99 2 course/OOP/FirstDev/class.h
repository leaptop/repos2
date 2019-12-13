#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include "const.h"

class figures
{
public:
	float getPosX() const;
    void setPosX(const float x);
	
	float getPosY() const;
    void setPosY(const float y);	
    
    int getColor() const;
    void setColor(const int color);	
    	
    
    virtual void draw() = 0;
    virtual void move() = 0;
    
    figures(){}
    
protected:
	float x;
	float y;
	int color;
};



class circleClass : public figures
{
public:
	void move();
	void draw();
	
	circleClass(float x, float y, int color):figures(){
		setPosX(x);
		setPosY(y);
		setColor(color);
	}
};

class triangleClass : public figures
{
public:
	void move();
    void draw();
	
	triangleClass(float x, float y, int color):figures(){
		setPosX(x);
		setPosY(y);
		setColor(color);
	}
};

class triangleLeftClass : public figures
{
public:
	void move();
    void draw();
	
	triangleLeftClass(float x, float y, int color):figures(){
		setPosX(x);
		setPosY(y);
		setColor(color);
	}
};

class triangleRightClass : public figures
{
public:
	void move();
    void draw();
	
	triangleRightClass(float x, float y, int color):figures(){
		setPosX(x);
		setPosY(y);
		setColor(color);
	}
};

class rectangleClass : public figures
{
public:
	void move();
	void draw();
	
	rectangleClass(float x, float y, int color):figures(){
		setPosX(x);
		setPosY(y);
		setColor(color);
	}
};


#endif
