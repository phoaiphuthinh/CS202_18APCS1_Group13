#pragma once
#include "vehicle.h"

class car : public Vehicle {
private:
public:
	car();
	car(int x, int y);
	~car();
	void draw();
	void makeSound();
};
