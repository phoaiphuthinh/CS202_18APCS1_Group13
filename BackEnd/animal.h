#pragma once
#include <string>
#include <Windows.h>
#include <mmsystem.h>

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
	virtual void draw(int x, int y) = 0;
	virtual void move(int sign); //left or right
	virtual void makeSound();
	int getX();
	int getY();
	bool getDestroy();
};

