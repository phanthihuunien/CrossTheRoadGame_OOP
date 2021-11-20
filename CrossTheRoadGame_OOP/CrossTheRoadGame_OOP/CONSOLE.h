#pragma once
#include <Windows.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void FixConsoleWindow();
void gotoXY(int x, int y);
void ShowConsoleCursor(bool showFlag);
void printTitle();
void SET_COLOR(int color);