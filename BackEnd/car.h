#pragma once
#include "vehicle.h"
#include "helper.h"

class car : public Vehicle {
private:
public:
	car();
	car(int x, int y);
	~car();
	void draw(int x, int y, int d);
	void makeSound();
	int getSign();
};
