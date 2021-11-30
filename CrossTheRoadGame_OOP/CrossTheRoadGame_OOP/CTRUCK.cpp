#include "CTRUCK.h"
CTRUCK::CTRUCK():CVEHICLE() {}
CTRUCK::CTRUCK(int x, int y):CVEHICLE(x,y) {}

int CTRUCK::numTruck=5;

void CTRUCK::Draw() {
	SET_COLOR(6);
	gotoXY(mX - 2, mY); cout <<char(220);
	gotoXY(mX - 1, mY); cout << char(219);
	gotoXY(mX, mY);cout<<char(219);
	SET_COLOR(0);
}
void CTRUCK::deleteChar() {
	gotoXY(mX - 2 , mY);cout << ' ';
	gotoXY(mX - 1, mY); cout << ' ';
	gotoXY(mX, mY); cout << ' ';
}

void CTRUCK::increaseNumTruck() {
	++numTruck;
}