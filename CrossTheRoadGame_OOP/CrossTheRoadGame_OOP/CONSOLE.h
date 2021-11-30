#pragma once
#include <windows.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void FixConsoleWindow();
void gotoXY(int x, int y);
void ShowConsoleCursor(bool showFlag);
void printTitle();
void SET_COLOR(int color);
void DrawBoard(int x, int y, int width, int height); 
