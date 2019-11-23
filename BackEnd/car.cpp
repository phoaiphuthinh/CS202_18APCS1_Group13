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

void car::draw(int x, int y, int d)
{
		if (d == 1)
		{
			gotoXY(x, y - 3);
			std::cout << "    _______       " << std::endl;
			gotoXY(x, y - 2);
			std::cout << " _//__|||__\\\\__ " << std::endl;
			gotoXY(x, y - 1);
			std::cout << "0/ \\___|____/ \\|" << std::endl;
			gotoXY(x, y);
			std::cout << " \\_/        \\_/ " << std::endl;
		}
		else
		{
			gotoXY(x, y - 3);
			std::cout << "    _______       " << std::endl;
			gotoXY(x, y - 2);
			std::cout << " _//__|||__\\\\__ " << std::endl;
			gotoXY(x, y - 1);
			std::cout << "|/ \\___|____/ \\0" << std::endl;
			gotoXY(x, y);
			std::cout << " \\_/        \\_/ " << std::endl;
		}
}

void car::makeSound()
{
	PlaySound(TEXT("carCrash.wav"), NULL, SND_SYNC);
}

int car::getSign() {
	return 1;
}