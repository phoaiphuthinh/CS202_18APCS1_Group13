#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
class helper {
public:
	static void FixConsoleWindow();
	static void gotoXY(int x, int y);
	static void textcolor(int x);
	static std::string yourname();
	static void clearMap();
	static void ShowConsoleCursor(bool showFlag);
	static void DrawRect(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
};

#endif // 
