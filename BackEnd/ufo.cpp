#include "ufo.h"

ufo::ufo()
{
	h = 20; //size of image
	w = 20; //size of image
}

ufo::ufo(int x, int y)
{
	mY = y;
	mX = x; 
	h = 20; //size of image
	w = 20; //size of image
}

void ufo::draw()
{
	//Coboloxi's work
}

void ufo::makeSound()
{
	PlaySound(TEXT("ufoCrash.wav"), NULL, SND_ASYNC);
}

int ufo::getSign() {
	return -1;
}