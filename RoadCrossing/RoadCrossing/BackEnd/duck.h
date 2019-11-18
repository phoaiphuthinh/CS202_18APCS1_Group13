#pragma once
#include "animal.h"

class Duck : public Animal {
private:

public:
	Duck();
	Duck(int x, int y);
	~Duck();
	void draw();
	void makeSound();
};