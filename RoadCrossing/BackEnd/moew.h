#pragma once
#include "animal.h"

class Moew : public Animal {
private:
	std::string icon[4];
public:
	Moew();
	Moew(int x, int y);
	~Moew();
	void draw();
	void clean();
	int getSign();
	void makeSound();
};