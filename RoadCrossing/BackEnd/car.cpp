#include "car.h"

car::car()
{
	h = 4; //size of image
	w = 16; //size of image
	icon[0] = "    _______     ";
	icon[1] = " _//__|||__\\\\__ ";
	icon[2] = "0/ \\___|____/ \\|";
	icon[3] = " \\_/        \\_/ ";
}

car::car(int x, int y)
{
	mY = y;
	mX = x;
	h = 4; //size of image
	w = 16; //size of image
	icon[0] = "    _______     ";
	icon[1] = " _//__|||__\\\\__ ";
	icon[2] = "0/ \\___|____/ \\|";
	icon[3] = " \\_/        \\_/ ";
}

void car::draw()
{
	//int d = getSign();
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
				putchar(icon[j][i]);
			putchar('\n');
		}
	}
}

void car::makeSound()
{
	PlaySound(TEXT("./sources/carCrash.wav"), NULL, SND_ASYNC);
}

int car::getSign() {
	return 1;
}

void car::clean()
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
