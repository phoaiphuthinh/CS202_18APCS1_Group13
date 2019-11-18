#pragma once
class Animal{
protected:
	int mX, mY; //Center point
	int h, w; //heigh and weight
	bool destroy = false; //true if out of screen
public:
	Animal();
	Animal(int x, int y);
	~Animal();
	virtual void draw() = 0;
	virtual void move(int sign); //left or right
	virtual void makeSound() = 0;

};

