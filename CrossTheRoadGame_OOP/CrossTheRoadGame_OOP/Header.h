#pragma once
#include<thread>
#include <Windows.h>
#include <string>
#include <cstdio>


const int MAXWIDTH = 115;
const int MAXHEIGHT = 25;
const int numLane = 5;
const int y_truck = 18;
const int y_car = 14;
const int y_bird = 10;
const int y_dinausor = 6;
static int choiceMenuStart;
static int choiceMenuInGame;
static bool sound = true;
static int LANE[5] = { 20, 16, 12, 8, 4 };
static int lv = 1;
void SubThread();

int StartMenu();

void EraseMenu();
int IngameMenu();