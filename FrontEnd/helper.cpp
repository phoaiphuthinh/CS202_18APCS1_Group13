#include "helper.h"

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

std::string yourname()
{
	std::string name;
	std::cout << "What is your name: ";
	getline(std::cin, name);
	return name;
}

void clearMap()
{
	gotoXY(0, 0);
	for (int j = 0; j < 43; j++)
	{
		if (j % 7 == 0) {}
		else {
			gotoXY(2, j);
			std::cout << "                                                                                                    ";
		}
	}
	gotoXY(0, 0);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void DrawRect(int x, int y, int width, int height, int curPosX, int curPosY)
{
	gotoXY(x, y); 
	std::cout << char(201);
	for (int i = 1; i < width; i++)
		std::cout << char(205);
	std::cout << char(187);
	gotoXY(x, height + y); 
	std::cout << char(200);
	for (int i = 1; i < width; i++)
		std::cout << char(205);
	std::cout << char(188);
	for (int i = y + 1; i < height + y; i++)
	{
		gotoXY(x, i); 
		std::cout << char(186);
		gotoXY(x + width, i); 
		std::cout << char(186);
	}
	gotoXY(curPosX, curPosY);
}