#include "CTRUCK.h"
#include "CVEHICLE.h"
#include "CONSOLE.h"
#include <iostream>
using namespace std;

void CTRUCK::Draw() {
	gotoXY(mX, mY);cout<<char(219);
	gotoXY(mX - 1, mY);cout<<char(219);
	gotoXY(mX - 2, mY);cout<<(220);
}
void CTRUCK::deleteChar() {
	gotoXY(mX, mY);
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	gotoXY(mX - 2, mY);
	cout << ' ';
}

void CTRUCK::increaseNumTruck() {
	++numTruck;
}