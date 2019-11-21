#pragma once
#include "animal.h"

class Moew : public Animal {
private:

public:
	Moew();
	Moew(int x, int y);
	~Moew();
	void draw(int x, int y);
};