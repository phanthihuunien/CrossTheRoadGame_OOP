#include "CONSOLE.h"
#include "CCAR.h"
#include "CVEHICLE.h"
#include <iostream>
using namespace std;

int CCAR::numCar =5;

void CCAR::Draw() {
	CVEHICLE::Draw();
	//GotoXY(mX, mY);
	//cout << " "<<char(220)<<char(220)<<" ";
	gotoXY(mX, mY + 1);
	cout << char(220)<<char(219)<<char(219)<<char(220);
	gotoXY(mX, mY + 2);
	cout << "o  o";
}

void CCAR::increaseNumCar() {
	++numCar;
}