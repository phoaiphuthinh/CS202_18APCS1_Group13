#pragma once
#include "animal.h"
#include "helper.h"

class Duck : public Animal {
private:
	
public:
	Duck();
	Duck(int x, int y);
	void draw(int x, int y, int d);
	int getSign();
};