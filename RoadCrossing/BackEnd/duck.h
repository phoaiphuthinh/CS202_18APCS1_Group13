#pragma once
#include "animal.h"

class Duck : public Animal {
private:
	std::string icon[4];
public:
	Duck();
	Duck(int x, int y);
	void draw();
	void clean();
	int getSign();
	void makeSound();
};