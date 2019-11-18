#include "animal.h"
/* Modify if necessary */
const int SCREEN_SIZE_WEIGHT = 129;
const int SCREEN_SIZE_HEIGHT = 29;

Animal::Animal() {

}

Animal::Animal(int x, int y) {

}

Animal::~Animal() {

}

void Animal::move(int sign) {
	mX += sign * w / 2;
	mY += sign * h / 2;
	if (mX - w / 2 > SCREEN_SIZE_WEIGHT || mX + w / 2 < 0 || mY - h / 2 > SCREEN_SIZE_HEIGHT || mY + h / 2 < 0)
		destroy = true;
	else
		draw();
}