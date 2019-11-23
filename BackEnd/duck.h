#pragma once
#include "animal.h"

class Duck : public Animal {
private:
	
public:
	Duck();
	Duck(int x, int y);
	void draw(int x, int y);
	int getSign();
};