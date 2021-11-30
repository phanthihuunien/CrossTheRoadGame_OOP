#include "CCAR.h"
int CCAR::numCar =5;
CCAR::CCAR():CVEHICLE() {}
CCAR::CCAR(int x, int y):CVEHICLE(x,y) {}
void CCAR::Draw() {
	SET_COLOR(5);
	gotoXY(mX - 1, mY);cout<<char(219);
	gotoXY(mX, mY - 1); cout << char(254);
	gotoXY(mX, mY); cout << char(219);
	gotoXY(mX + 1, mY);cout<<char(219);
	SET_COLOR(0);
}
void CCAR::deleteChar() {
	gotoXY(mX - 1, mY);
	cout << ' ';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX, mY);
	cout << ' ';
	gotoXY(mX + 1, mY);
	cout << ' ';
}

void CCAR::increaseNumCar() {
	++numCar;
}