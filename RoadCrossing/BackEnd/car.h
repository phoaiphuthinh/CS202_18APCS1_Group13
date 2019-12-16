#pragma once
#include "vehicle.h"
#include "../FrontEnd/helper.h"
class car : public Vehicle {
private:
	std::string icon[4];
public:
	car();
	car(int x, int y);
	~car();
	void draw();
	void makeSound();
	int getSign();
	void clean();
};
