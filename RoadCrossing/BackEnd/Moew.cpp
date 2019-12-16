#include "Moew.h"

Moew::Moew() {
	h = 4;
	w = 12;
	icon[0] = "    _____  ";
	icon[1] = "^..^     \\9";
	icon[2] = "(oo)_____/ ";
	icon[3] = "   WW  WW  ";
}

Moew::Moew(int x, int y) : Animal(x, y) {
	h = 4;
	w = 12;
	icon[0] = "    _____  ";
	icon[1] = "^..^     \\9";
	icon[2] = "(oo)_____/ ";
	icon[3] = "   WW  WW  ";
}

Moew::~Moew() {

}

void Moew::draw() {

	int d = getSign();
	int x = mX;
	int y = mY;
	//std::string line1;
	//std::string line2;
	//std::string line3;
	//std::string line4;
	//if (d == -1)
	//{
	//	line1 = "    _____  ";
	//	line2 = "^..^     \\9";
	//	line3 = "(oo)_____/ ";
	//	line4 = "   WW  WW  ";
	//}
	//else
	//{
	//	line1 = "  _____     ";
	//	line2 = " /     ^..^ ";
	//	line3 = "6\\____ (oo) ";
	//	line4 = "  WW  WW    ";
	//}
	if (x >= 2 && x <= 101 - icon[1].length() + 1)
	{
		for (int i = 0; i < h; i++)
		{
			helper::gotoXY(x, y + i - 3);
			for (int j = 0; j < w; j++)
			{
				putchar(icon[i][j]);
			}
			putchar('\n');
		}
	}
	else if (x < 2)
	{
		for (int j = 0; j < 4; j++)
		{
			helper::gotoXY(2, y - 3 + j);
			for (int i = 2 - x; i < w ; i++)
			{
				putchar(icon[j][i]);
			}
			putchar('\n');
		}
	}
	else if (x > 101 - icon[1].length() + 1)
	{
		for (int j = 0; j < 4; j++)
		{
			helper::gotoXY(x, y - 3 + j);
			for (int i = 0; i < w - (x - (101 - w + 1)); i++)
			{
				putchar(icon[j][i]);
			}
			putchar('\n');
		}
	}
}

void Moew::clean()
{
	int x = mX;
	int y = mY;
	/*std::cout << x;
	system("pause>nul");*/
	if (x + w >= 0 && x <= 101 - w)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = x + w; j <= x + w - getSign() * w / 2; j++)
			{
				helper::gotoXY(j, y + i - 3);
				printf(" ");
			}
			putchar('\n');
		}
	}
	if (x + w < 0 || x > 101 - w)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 2; j <= 2 + w - getSign() * w / 2; j++)
			{
				helper::gotoXY(j, y + i - 3);
				printf(" ");
			}
			putchar('\n');
		}
	}
}

int Moew::getSign() {
	return -1;
}

void Moew::makeSound() {
	PlaySound(TEXT("./sources/pig.wav"), NULL, SND_ASYNC);
}