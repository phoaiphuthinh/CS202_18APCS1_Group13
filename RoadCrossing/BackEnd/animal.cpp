#include "animal.h"
/* Modify if necessary */
const int SCREEN_SIZE_WIDTH = 101;
const int SCREEN_SIZE_HEIGHT = 29;

Animal::Animal() {
	h = 20;
	w = 20;
}

Animal::Animal(int x, int y) {
	mX = x;
	mY = y;
	h = 20;
	w = 10;
}

Animal::~Animal() {

}

void Animal::move(int sign) {
	mX += sign * w / 2;
	if (mX + w / 2 < 0)
		mX = SCREEN_SIZE_WIDTH - w / 2;
	if (mX - w / 2 > SCREEN_SIZE_WIDTH)
		mX = -w / 2;
	//helper::gotoXY(1, 40);
	//std::cerr << mX << " ";
}


int Animal::getX() {
	return mX;
}

int Animal::getY() {
	return mY;
}

bool Animal::getDestroy() {
	return destroy;
}

void Animal::makeSound() {
	PlaySound(TEXT(("./sources/" + sound + ".wav").c_str()), NULL, SND_ASYNC);
}

int Animal::getWidth() {
	return w;
}