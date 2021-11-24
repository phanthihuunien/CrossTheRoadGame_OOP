#include "CONSOLE.h"
#include "CCAR.h"
#include "CVEHICLE.h"
#include <iostream>
using namespace std;

void CCAR::Draw() {
	gotoXY(mX, mY);cout<<char(219);
	gotoXY(mX, mY - 1);cout<<char(254);
	gotoXY(mX - 1, mY);cout<<char(219);
	gotoXY(mX + 1, mY);cout<<char(219);
}
void CCAR::deleteChar() {
	gotoXY(mX, mY);
	cout << ' ';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	gotoXY(mX + 1, mY);
	cout << ' ';
}

void CCAR::increaseNumCar() {
	++numCar;
}