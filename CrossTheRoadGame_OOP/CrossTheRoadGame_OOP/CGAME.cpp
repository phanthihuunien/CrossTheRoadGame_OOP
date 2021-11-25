#include"CGAME.h"
#include <string>
#include <iostream>

string stringEnd = "Dead, type y to continue or anykey to exit";

CGAME::CGAME()
{
	int level = getPeople().getLevel();
	axt = new CTRUCK[level];
	axh = new CCAR[level];
	akl = new CDINAUSOR[level];
	ac = new CBIRD[level];
	for (int i = 0; i < level; i++) {
		int x_animal = MAXWIDTH - 11 * i - 5;
		int x_vehical = 11 * i + 5;
		ac[i].set(x_animal, y_bird);
		akl[i].set(x_animal, y_dinausor);
		axt[i].set(x_vehical, y_truck);
		axh[i].set(x_vehical, y_car);
	}
}

void CGAME::drawGame()
{
}

void CGAME::drawBackground() {
	system("color 80");
	for (int i = 0; i < MAXHEIGHT; i++) {
		for (int j = 2; j < MAXWIDTH + 1; j++) {
			if (j == MAXWIDTH || j == 2) {
				gotoXY(j, i);
				cout << "|";
			}
			else if (i == MAXHEIGHT - 1 || i % 4 == 0) {
				if (j % 4 == 0) {
					SET_COLOR(7);
					gotoXY(j, i);
					cout << (char)219;
					cout << (char)219;
					cout << (char)219;

				}
			}
		}
	}
}
CTRUCK* CGAME::getTruck() {
	return axt;
}
CCAR* CGAME::getCar() {
	return axh;
}
CBIRD* CGAME::getBird() {
	return ac;
}
CDINAUSOR* CGAME::getDinausor() {
	return akl;
}
void CGAME::updatePosAnimal() {
	int level = getPeople().getLevel();
	for (int i = 0; i < level; i++) {
		ac[i].deleteChar();
		ac[i].Move();
	}
	for (int i = 0; i < level; i++) {
		akl[i].deleteChar();
		akl[i].Move();
	}
}
void CGAME::updatePosVehicle() {
	int level = getPeople().getLevel();
	for (int i = 0; i < level; i++) {
		axt[i].deleteChar();
		axt[i].Move();
	}
	for (int i = 0; i < level; i++) {
		axh[i].deleteChar();
		axh[i].Move();
	}
}
CGAME::~CGAME()
{
	delete[]axt;
	delete[]axh;
	delete[]akl;
	delete[]ac;
}

CPEOPLE CGAME::getPeople()
{
	return CPEOPLE();
}


void CGAME::startGame() {
	system("cls");
	DrawBoard(0, 0, MAXWIDTH, MAXHEIGHT);
	this->drawBackground();

	gotoXY(MAXWIDTH / 6 + 2, MAXHEIGHT + 3);
	cout << "SAVE (L)";
	gotoXY(MAXWIDTH / 6 * 2 + 2, MAXHEIGHT + 3);
	cout << "LOAD (T)";
	gotoXY(MAXWIDTH / 6 * 3 + 2, MAXHEIGHT + 3);
	cout << "EXIT (ESC)";
	gotoXY(MAXWIDTH / 6 * 4 + 2, MAXHEIGHT + 3);
	cout << "PAUSE (P) ";

	//this->getPeople().isLive() = true;
}

void CGAME::clearGame(){
   
}

void CGAME::resetGame(){
	SET_COLOR(15);
	clearGame();

	int sizeStr = stringEnd.length();
	gotoXY(MAXWIDTH / 5 + 2, MAXHEIGHT + 1);
	for (int i = 0; i < sizeStr; i++) cout << " ";
	CGAME* cg = new CGAME();
	*this = *cg;

	this->getPeople().isLive() = false;
}