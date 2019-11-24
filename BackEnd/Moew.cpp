#include "Moew.h"

Moew::Moew() {

}

Moew::Moew(int x, int y) : Animal(x, y) {

}

Moew::~Moew() {

}

void Moew::draw() {
	int d = getSign();
	int x = mX;
	int y = mY;
	std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;
	if (d == 1)
	{
		line1 = "    _____  ";
		line2 = "^..^     \\9";
		line3 = "(oo)_____/ ";
		line4 = "   WW  WW  ";
	}
	else
	{
		line1 = "  _____     ";
		line2 = " /     ^..^ ";
		line3 = "6\\____ (oo) ";
		line4 = "  WW  WW    ";
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

int Moew::getSign() {
	return -1;
}