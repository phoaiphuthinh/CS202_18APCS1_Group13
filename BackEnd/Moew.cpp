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
	if (d == 1)
	{
		gotoXY(x, y - 3);
		std::cout << "    _____  " << std::endl;
		gotoXY(x, y - 2);
		std::cout << "^..^     \\9" << std::endl;
		gotoXY(x, y - 1);
		std::cout << "(oo)_____/ " << std::endl;
		gotoXY(x, y - 0);
		std::cout << "   WW  WW  " << std::endl;
	}
	else
	{
		gotoXY(x, y - 3);
		std::cout << "  _____     " << std::endl;
		gotoXY(x, y - 2);
		std::cout << " /     ^..^ " << std::endl;
		gotoXY(x, y - 1);
		std::cout << "6\\____ (oo)" << std::endl;
		gotoXY(x, y - 0);
		std::cout << "  WW  WW    " << std::endl;
	}
}

int Moew::getSign() {
	return -1;
}