#include "shape.h"
#include "helper.h"

void drawcar(int x, int y,int d)
{
	string line1;
	string line2;
	string line3;
	string line4;
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


		if (x>=2 && x <= 101 - line1.length() + 1)
		{
		helper::gotoXY(x, y - 3);
		cout << line1 << endl;
		helper::gotoXY(x, y - 2);
		cout << line2 << endl;
		helper::gotoXY(x, y - 1);
		cout << line3 << endl;
		helper::gotoXY(x, y - 0);
		cout << line4 << endl;
		}
		else if (x <2)
		{
			helper::gotoXY(2, y - 3);
			for (int i=2-x;i<line1.length()-1;i++)
				cout << line1[i];
			cout << endl;
			helper::gotoXY(2, y - 2);
			for (int i =2-x; i < line2.length() - 1; i++)
				cout << line2[i];
			cout << endl;

			helper::gotoXY(2, y - 1);
			for (int i = 2-x; i < line3.length() - 1; i++)
				cout << line3[i];
			cout << endl;

			helper::gotoXY(2, y - 0);
			for (int i = 2-x; i < line4.length() - 1; i++)
				cout << line4[i];
			cout<< endl;
		}
		else if (x > 101-line1.length()+1)
		{
			helper::gotoXY(x, y - 3);
			for (int i = 0; i < line1.length() - (x-(101-line1.length()+1)); i++)
				cout << line1[i];
			cout << endl;
			helper::gotoXY(x, y - 2);
			for (int i = 0; i < line2.length() - (x - (101 - line2.length() + 1)); i++)
				cout << line2[i];
			cout << endl;

			helper::gotoXY(x, y - 1);
			for (int i = 0; i < line3.length() - (x - (101 - line3.length() + 1)); i++)
				cout << line3[i];
			cout << endl;

			helper::gotoXY(x, y - 0);
			for (int i = 0; i < line4.length() - (x - (101 - line4.length() + 1)); i++)
				cout << line4[i];
			cout << endl;
		}
}

void drawduck(int x, int y, int d)
{
	string line1;
	string line2;
	string line3;
	string line4;
	if (d == 1)
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
	}

	if (x >= 2 && x <= 101 - line1.length() + 1)
	{
		helper::gotoXY(x, y - 3);
		cout << line1 << endl;
		helper::gotoXY(x, y - 2);
		cout << line2 << endl;
		helper::gotoXY(x, y - 1);
		cout << line3 << endl;
		helper::gotoXY(x, y - 0);
		cout << line4 << endl;
	}
	else if (x < 2)
	{
		helper::gotoXY(2, y - 3);
		for (int i = 2 - x; i < line1.length() - 1; i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(2, y - 2);
		for (int i = 2 - x; i < line2.length() - 1; i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(2, y - 1);
		for (int i = 2 - x; i < line3.length() - 1; i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(2, y - 0);
		for (int i = 2 - x; i < line4.length() - 1; i++)
			cout << line4[i];
		cout << endl;
	}
	else if (x > 101 - line1.length() + 1)
	{
		helper::gotoXY(x, y - 3);
		for (int i = 0; i < line1.length() - (x - (101 - line1.length() + 1)); i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(x, y - 2);
		for (int i = 0; i < line2.length() - (x - (101 - line2.length() + 1)); i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(x, y - 1);
		for (int i = 0; i < line3.length() - (x - (101 - line3.length() + 1)); i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(x, y - 0);
		for (int i = 0; i < line4.length() - (x - (101 - line4.length() + 1)); i++)
			cout << line4[i];
		cout << endl;
	}
}

void drawufo(int x, int y, int d)
{
	string line1 = "  .------.  ";
	string line2 = "_/` oooo `\\_";
	string line3 = " `-=.==.=-' ";
	string line4 = "    V  V    ";

	if (x >= 2 && x <= 101 - line1.length() + 1)
	{
		helper::gotoXY(x, y - 3);
		cout << line1 << endl;
		helper::gotoXY(x, y - 2);
		cout << line2 << endl;
		helper::gotoXY(x, y - 1);
		cout << line3 << endl;
		helper::gotoXY(x, y - 0);
		cout << line4 << endl;
	}
	else if (x < 2)
	{
		helper::gotoXY(2, y - 3);
		for (int i = 2 - x; i < line1.length() - 1; i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(2, y - 2);
		for (int i = 2 - x; i < line2.length() - 1; i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(2, y - 1);
		for (int i = 2 - x; i < line3.length() - 1; i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(2, y - 0);
		for (int i = 2 - x; i < line4.length() - 1; i++)
			cout << line4[i];
		cout << endl;
	}
	else if (x > 101 - line1.length() + 1)
	{
		helper::gotoXY(x, y - 3);
		for (int i = 0; i < line1.length() - (x - (101 - line1.length() + 1)); i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(x, y - 2);
		for (int i = 0; i < line2.length() - (x - (101 - line2.length() + 1)); i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(x, y - 1);
		for (int i = 0; i < line3.length() - (x - (101 - line3.length() + 1)); i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(x, y - 0);
		for (int i = 0; i < line4.length() - (x - (101 - line4.length() + 1)); i++)
			cout << line4[i];
		cout << endl;
	}
}

void drawpig(int x, int y, int d)
{
	string line1;
	string line2;
	string line3;
	string line4;
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
		helper::gotoXY(x, y - 3);
		cout << line1 << endl;
		helper::gotoXY(x, y - 2);
		cout << line2 << endl;
		helper::gotoXY(x, y - 1);
		cout << line3 << endl;
		helper::gotoXY(x, y - 0);
		cout << line4 << endl;
	}
	else if (x < 2)
	{
		helper::gotoXY(2, y - 3);
		for (int i = 2 - x; i < line1.length() - 1; i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(2, y - 2);
		for (int i = 2 - x; i < line2.length() - 1; i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(2, y - 1);
		for (int i = 2 - x; i < line3.length() - 1; i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(2, y - 0);
		for (int i = 2 - x; i < line4.length() - 1; i++)
			cout << line4[i];
		cout << endl;
	}
	else if (x > 101 - line1.length() + 1)
	{
		helper::gotoXY(x, y - 3);
		for (int i = 0; i < line1.length() - (x - (101 - line1.length() + 1)); i++)
			cout << line1[i];
		cout << endl;
		helper::gotoXY(x, y - 2);
		for (int i = 0; i < line2.length() - (x - (101 - line2.length() + 1)); i++)
			cout << line2[i];
		cout << endl;

		helper::gotoXY(x, y - 1);
		for (int i = 0; i < line3.length() - (x - (101 - line3.length() + 1)); i++)
			cout << line3[i];
		cout << endl;

		helper::gotoXY(x, y - 0);
		for (int i = 0; i < line4.length() - (x - (101 - line4.length() + 1)); i++)
			cout << line4[i];
		cout << endl;
	}
}

void drawboder()
{
	cout << "  ";
	for (int i = 0; i < 42; i++)
	{
		helper::gotoXY(1, 1 + i);
		cout << "|";
	}
	for (int i = 0; i < 100; i++)
	{
		helper::gotoXY(2 + i, 0);
		cout << "_";
		helper::gotoXY(2+i, 7);
		cout << "_";
		helper::gotoXY(2+i, 14);
		cout << "_";
		helper::gotoXY(2+i, 21);
		cout << "_";
		helper::gotoXY(2+i, 28);
		cout << "_";
		helper::gotoXY(2+i, 35);
		cout << "_";
		helper::gotoXY(2 + i, 42);
		cout << "_";
	}
	for (int i = 0; i < 42; i++)
	{
		helper::gotoXY(102, 1 + i);
		cout << "|";
	}
	drawduck(2, 12, 1);
	drawcar(2, 19, 1);
	drawufo(2, 26, 1);
	drawpig(2, 33, 1);
	cout << "\n\n\n\n\n\n\n\n\n\n";
	system("pause");
}


