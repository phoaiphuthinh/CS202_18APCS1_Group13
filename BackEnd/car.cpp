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
	int d = getSign();
	int x = mX;
	int y = mY;
	std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;
	if (d == 1)
	{
		line1 = "    _______     ";
		line2 = " _//__|||__\\\\__ ";
		line3 = "0/ \\___|____/ \\|";
		line4 = " \\_/        \\_/ ";
	}
	else
	{
		line1 = "    _______     ";
		line2 = " _//__|||__\\\\__ ";
		line3 = "|/ \\___|____/ \\0";
		line4 = " \\_/        \\_/ ";
	}


	if (x >= 2 && x <= 101 - line1.length() + 1)
	{
		gotoXY(x, y - 3);
		std::cout << line1 << std::endl;
		gotoXY(x, y - 2);
		std::cout << line2 << std::endl;
		gotoXY(x, y - 1);
		std::cout << line3 << std::endl;
		gotoXY(x, y - 0);
		std::cout << line4 << std::endl;
	}
	else if (x < 2)
	{
		gotoXY(2, y - 3);
		for (int i = 2 - x; i < line1.length() - 1; i++)
			std::cout << line1[i];
		std::cout << std::endl;
		gotoXY(2, y - 2);
		for (int i = 2 - x; i < line2.length() - 1; i++)
			std::cout << line2[i];
		std::cout << std::endl;

		gotoXY(2, y - 1);
		for (int i = 2 - x; i < line3.length() - 1; i++)
			std::cout << line3[i];
		std::cout << std::endl;

		gotoXY(2, y - 0);
		for (int i = 2 - x; i < line4.length() - 1; i++)
			std::cout << line4[i];
		std::cout << std::endl;
	}
	else if (x > 101 - line1.length() + 1)
	{
		gotoXY(x, y - 3);
		for (int i = 0; i < line1.length() - (x - (101 - line1.length() + 1)); i++)
			std::cout << line1[i];
		std::cout << std::endl;
		gotoXY(x, y - 2);
		for (int i = 0; i < line2.length() - (x - (101 - line2.length() + 1)); i++)
			std::cout << line2[i];
		std::cout << std::endl;

		gotoXY(x, y - 1);
		for (int i = 0; i < line3.length() - (x - (101 - line3.length() + 1)); i++)
			std::cout << line3[i];
		std::cout << std::endl;

		gotoXY(x, y - 0);
		for (int i = 0; i < line4.length() - (x - (101 - line4.length() + 1)); i++)
		std::cout << line4[i];
		std::cout << std::endl;
	}
}

void car::makeSound()
{
	PlaySound(TEXT("./sources/carCrash.wav"), NULL, SND_SYNC);
}

int car::getSign() {
	return 1;
}