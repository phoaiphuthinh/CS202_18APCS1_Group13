#include "shape.h"
#include "helper.h"

void drawcar(int x, int y,int d)
{
	if (d == 1)
	{
		gotoXY(x, y - 3);
		cout << "    _______       " << endl;
		gotoXY(x, y - 2);
		cout << " _//__|||__\\\\__ " << endl;
		gotoXY(x, y - 1);
		cout << "0/ \\___|____/ \\|" << endl;
		gotoXY(x, y);
		cout << " \\_/        \\_/ " << endl;
	}
	else
	{
		gotoXY(x, y - 3);
		cout << "    _______       " << endl;
		gotoXY(x, y - 2);
		cout << " _//__|||__\\\\__ " << endl;
		gotoXY(x, y - 1);
		cout << "|/ \\___|____/ \\0" << endl;
		gotoXY(x, y);
		cout << " \\_/        \\_/ " << endl;
	}
}

void drawduck(int x, int y, int d)
{
	if (d == 1)
	{
		gotoXY(x, y - 3);
		cout << "  __    " << endl;
		gotoXY(x, y - 2);
		cout << "=(o )___" << endl;
		gotoXY(x, y - 1);
		cout << " ( ._> /" << endl;
		gotoXY(x, y - 0);
		cout << "  `---' " << endl;
	}
	else
	{
		gotoXY(x, y - 3);
		cout << "    __  " << endl;
		gotoXY(x, y - 2);
		cout << "___( o)=" << endl;
		gotoXY(x, y - 1);
		cout << "\\ <_. )" << endl;
		gotoXY(x, y - 0);
		cout << " `---'  " << endl;
	}
}

void drawufo(int x, int y, int d)
{
	gotoXY(x, y - 3);
	cout << "  .------." << endl;
	gotoXY(x, y - 2);
	cout << "_/` oooo `\\_" << endl;
	gotoXY(x, y - 1);
	cout << " `-=.==.=-'" << endl;
	gotoXY(x, y - 0);
	cout << "    V  V" << endl;
}

void drawpig(int x, int y, int d)
{
	if (d == 1)
	{
		gotoXY(x, y - 3);
		cout << "    _____  " << endl;
		gotoXY(x, y - 2);
		cout << "^..^     \\9" << endl;
		gotoXY(x, y - 1);
		cout << "(oo)_____/ " << endl;
		gotoXY(x, y - 0);
		cout << "   WW  WW  " << endl;
	}
	else
	{
		gotoXY(x, y - 3);
		cout << "  _____     " << endl;
		gotoXY(x, y - 2);
		cout << " /     ^..^ " << endl;
		gotoXY(x, y - 1);
		cout << "6\\____ (oo)" << endl;
		gotoXY(x, y - 0);
		cout << "  WW  WW    " << endl;
	}
}

void drawboder()
{
	cout << "  ";
	for (int i = 0; i < 42; i++)
	{
		gotoXY(1, 1 + i);
		cout << "|";
	}
	for (int i = 0; i < 100; i++)
	{
		gotoXY(2 + i, 0);
		cout << "_";
		gotoXY(2+i, 7);
		cout << "_";
		gotoXY(2+i, 14);
		cout << "_";
		gotoXY(2+i, 21);
		cout << "_";
		gotoXY(2+i, 28);
		cout << "_";
		gotoXY(2+i, 35);
		cout << "_";
		gotoXY(2 + i, 42);
		cout << "_";
	}
	for (int i = 0; i < 42; i++)
	{
		gotoXY(102, 1 + i);
		cout << "|";
	}
}


