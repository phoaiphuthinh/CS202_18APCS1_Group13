#include "duck.h"

Duck::Duck() {
	sound = "boloxi";
}

Duck::Duck(int x, int y) : Animal(x,y) {
	sound = "boloxi";
}

void Duck::draw(int x, int y,int d) {
	if (d == 1)
	{
		gotoXY(x, y - 3);
		std::cout << "  __    " << std::endl;
		gotoXY(x, y - 2);
		std::cout << "=(o )___" << std::endl;
		gotoXY(x, y - 1);
		std::cout << " ( ._> /" << std::endl;
		gotoXY(x, y - 0);
		std::cout << "  `---' " << std::endl;
	}
	else
	{
		gotoXY(x, y - 3);
		std::cout << "    __  " << std::endl;
		gotoXY(x, y - 2);
		std::cout << "___( o)=" << std::endl;
		gotoXY(x, y - 1);
		std::cout << "\\ <_. )" << std::endl;
		gotoXY(x, y - 0);
		std::cout << " `---'  " << std::endl;
	}
}

int Duck::getSign() {
	return 1;
}