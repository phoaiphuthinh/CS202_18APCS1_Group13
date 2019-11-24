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
	int x = mX;
	int y = mY;
		gotoXY(x, y - 3);
		std::cout << "  .------." << std::endl;
		gotoXY(x, y - 2);
		std::cout << "_/` oooo `\\_" <<std:: endl;
		gotoXY(x, y - 1);
		std::cout << " `-=.==.=-'" << std::endl;
		gotoXY(x, y - 0);
		std::cout << "    V  V" << std::endl;
	
}

void ufo::makeSound()
{
	PlaySound(TEXT("ufoCrash.wav"), NULL, SND_ASYNC);
}

int ufo::getSign() {
	return -1;
}