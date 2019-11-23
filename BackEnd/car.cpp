#include "car.h"

car::car()
{
	h = 20; //size of image
	w = 20; //size of image
}

car::car(int x, int y)
{
	mY = y;
	mX = x;
	h = 20; //size of image
	w = 20; //size of image
}

void car::draw()
{
	//Coboloxi's work
}

void car::makeSound()
{
	PlaySound(TEXT("carCrash.wav"), NULL, SND_SYNC);
}

int car::getSign() {
	return 1;
}