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
	if (dxt.getLight()) {
		SET_COLOR(2);
		gotoXY(MAXWIDTH + 1, 17);
		cout << char(254);
		SET_COLOR(8);
	}
	else if (!dxt.getLight()) {
		SET_COLOR(4);
		gotoXY(MAXWIDTH + 1, 18);
		cout << char(254);
		SET_COLOR(8);
	}
	if (dxh.getLight()) {
		SET_COLOR(2);
		gotoXY(1, 13);
		cout << char(254);
		SET_COLOR(8);
	}
	else if (!dxh.getLight()) {
		SET_COLOR(4);
		gotoXY(1, 14);
		cout << char(254);
		SET_COLOR(8);
	}
	for (int i = 0; i < cn.getLevel(); i++) {
		axt[i].Draw();
		axh[i].Draw();
		ac[i].Draw();
		akl[i].Draw();
	}
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

//void CGAME::resetGame(){
//	SetColor(15);
//	clearGame();
//
//	int sizeStr = stringEnd.length();
//	GotoXY(WIDTH / 5 + 2, HEIGHT + 1);
//	for (int i = 0; i < sizeStr; i++) cout << " ";
//	CGAME* cg = new CGAME(velocity, numOfObj, isSound);
//	*this = *cg;
//
//	this->getPeople().isLive() = false;
//}
//
//void CGAME::clearGame(){
//    system("cls");
//    for (int i = 0; i < carSize; i++)
//		this->getCar()[i].draw("_");
//	for (int i = 0; i < truckSize; i++)
//		this->getTruck()[i].draw("_");
//
//	for (int i = 0; i < dinausorSize; i++)
//		this->getDinauour()[i].draw("_");
//	for (int i = 0; i < birdSize; i++)
//		this->getBird()[i].draw("_");
//
//	int xCNSize = this->getPeople().getX().size();
//	for (int i = 0; i < xCNSize; i++)
//	if (this->getPeople().getY()[i] % 4 == 0 && this->getPeople().getY()[i] != MAXHEIGHT - 1 - i)
//		this->getPeople().draw("_");
//	else
//		this->getPeople().draw(" ");
//
//	for (int i = 0; i < numLane; i++)
//	{
//		gotoXY(this->getPeople().getX()[0], LANE[i]);
//		cout << "_";
//		gotoXY(this->getPeople().getX()[0], LANE[i] + 1);
//		cout << " ";
//	}
//}
//
//void CGAME::resetGame(){
//	SET_COLOR(15);
//	clearGame();
//
//	int sizeStr = stringEnd.length();
//	gotoXY(MAXWIDTH / 5 + 2, MAXHEIGHT + 1);
//	for (int i = 0; i < sizeStr; i++) cout << " ";
//	CGAME* cg = new CGAME();
//	*this = *cg;
//
//	this->getPeople().isLive() = false;
//}