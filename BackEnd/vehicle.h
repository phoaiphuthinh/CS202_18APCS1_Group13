#pragma once
#include <Windows.h>
#include<MMSystem.h>



class Vehicle
{
protected:
	int mX, mY;
	int h, w; //height and width
	bool destroy = false; //true if out of screen
public:
	Vehicle();
	~Vehicle();
	int getX();;
	int getY();;
	int getWidth();;
	virtual void draw(int x,int y, int d) = 0;
	virtual void move(int sign); //left or right
	virtual void makeSound() = 0;
	virtual int getSign() = 0;
};

