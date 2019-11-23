#pragma once
#include "vehicle.h"

class ufo : public Vehicle {
private:
public:
	ufo();
	ufo(int x, int y);
	~ufo();
	void draw();
	void makeSound();
	int getSign();
};
