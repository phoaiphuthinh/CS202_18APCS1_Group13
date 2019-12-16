#pragma once
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include "../FrontEnd/helper.h"
class Animal{
protected:
	int mX, mY; //Center point
	int h, w; //height and width
	bool destroy = false; //true if out of screen
	std::string sound = "";
public:
	Animal();
	Animal(int x, int y);
	~Animal();
	virtual void draw() = 0;
	virtual void clean() = 0;
	virtual void move(int sign); //left or right
	virtual void makeSound();
	virtual int getSign() = 0;
	int getX();
	int getY();
	int getWidth();
	bool getDestroy();
};

