#include<iostream>
using namespace std;
#include"CGAME.h"
#include"CONSOLE.h"
#include<vector>

int main() {
	FixConsoleWindow();
	ShowConsoleCursor(0);
	CGAME cg;
	cg.drawBackground();
	cg.drawGame();
	cg.getPeople().DrawPLayer();
	while (true);
}
