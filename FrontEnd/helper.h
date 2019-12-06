#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<string>

void FixConsoleWindow();
void gotoXY(int x, int y);
void textcolor(int x);
std::string yourname();
void clearMap();
void ShowConsoleCursor(bool showFlag);
void DrawRect(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
#endif // 
