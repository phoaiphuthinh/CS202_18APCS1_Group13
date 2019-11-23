#pragma once
#include "animal.h"
#include "helper.h"

class Moew : public Animal {
private:

public:
	Moew();
	Moew(int x, int y);
	~Moew();
	void draw(int x, int y, int d);
	int getSign();
};