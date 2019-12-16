#include "duck.h"

Duck::Duck() {
	sound = "boloxi";
	h = 4;
	w = 8;
	icon[0] = "    __  ";
	icon[1] = "___( o)=";
	icon[2] = "\\ <_. ) ";
	icon[3] = " `---'  ";
}

Duck::Duck(int x, int y) : Animal(x, y) {
	sound = "boloxi";
	h = 4;
	w = 8;
	icon[0] = "    __  ";
	icon[1] = "___( o)=";
	icon[2] = "\\ <_. ) ";
	icon[3] = " `---'  ";
}

void Duck::draw() {
	int d = getSign();
	int x = mX;
	int y = mY;
	/*std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;*/
	/*if (d == -1)
	{
		line1 = "  __    ";
		line2 = "=(o )___";
		line3 = " ( ._> /";
		line4 = "  `---' ";
	}
	else
	{
		line1 = "    __  ";
		line2 = "___( o)=";
		line3 = "\\ <_. ) ";
		line4 = " `---'  ";
	}*/

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
			for (int i = 2 - x; i < icon[j].length() - 1; i++)
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

int Duck::getSign() {
	return 1;
}

void Duck::makeSound() {
	PlaySound(TEXT("./sources/duck.wav"), NULL, SND_ASYNC);
}
void Duck::clean()
{
	int x = mX;
	int y = mY;

	if (x >= 2 && x <= 101 - w)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = x - 1; j >= x - getSign() * w / 2; j--)
			{
				helper::gotoXY(j, y + i - 3);
				printf(" ");
			}
			putchar('\n');
		}
	}
	else if (x > 101 - w)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = x - 1; j >= x - getSign() * w / 2; j--)
			{
				helper::gotoXY(j, y + i - 3);
				printf(" ");
			}
			putchar('\n');
		}
	}
}