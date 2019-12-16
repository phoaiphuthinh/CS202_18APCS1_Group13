#include "ufo.h"

ufo::ufo()
{
	h = 4; //size of image
	w = 12; //size of image
	icon[0] = "  .------.  ";
	icon[1] = "_/` oooo `\\_";
	icon[2] = " `-=.==.=-' ";
	icon[3] = "    V  V    ";
}

ufo::ufo(int x, int y)
{
	mY = y;
	mX = x;
	h = 4; //size of image
	w = 12; //size of image
	icon[0] = "  .------.  ";
	icon[1] = "_/` oooo `\\_";
	icon[2] = " `-=.==.=-' ";
	icon[3] = "    V  V    ";
}

void ufo::draw()
{
	int x = mX;
	int y = mY;
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
			for (int i = 2 - x; i < w; i++)
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

void ufo::clean()
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

void ufo::makeSound()
{
	PlaySound(TEXT("./sources/ufoCrash.wav"), NULL, SND_ASYNC);
}

int ufo::getSign() {
	return -1;
}