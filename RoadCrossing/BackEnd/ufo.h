#pragma once
#include "vehicle.h"

class ufo : public Vehicle {
private:
	std::string icon[4];
public:
	ufo();
	ufo(int x, int y);
	~ufo();
	void draw();
	void clean();
	void makeSound();
	int getSign();
};
