#pragma once
#include "vehicle.h"
#include "../FrontEnd/helper.h"
class car : public Vehicle {
private:
public:
	car();
	car(int x, int y);
	~car();
	void draw();
	void makeSound();
	int getSign();
};
