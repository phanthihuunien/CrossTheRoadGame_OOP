#include "CTRUCK.h"
#include "CVEHICLE.h"
#include "CONSOLE.h"
#include <iostream>
using namespace std;

void CTRUCK::Draw() {
	CVEHICLE::Draw();
	//GotoXY(mX, mY);
	//cout << char(220)<<char(220)<<char(220);
	gotoXY(mX, mY + 1);
	cout << char(219)<<char(219)<<char(219)<<char(220);
	gotoXY(mX, mY + 2);
	cout << "o  o";
}

void CTRUCK::increaseNumTruck() {
	++numTruck;
}