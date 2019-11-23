#pragma once
#include "vehicle.h"
#include "helper.h"

class ufo : public Vehicle {
private:
public:
	ufo();
	ufo(int x, int y);
	~ufo();
	void draw(int x, int y, int d);
	void makeSound();
	int getSign();
};
