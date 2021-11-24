#include "CVEHICLE.h"
#include "CONSOLE.h"
#include "Header.h"
#include <iostream>
using namespace std;

void CVEHICLE::Move(){
	mX--;
	if (mX == 2)
	{
		mX = MAXWIDTH - 2;
	}
}

CVEHICLE::CVEHICLE() {
	mX = 0;
	mY = 0;
}
CVEHICLE::CVEHICLE(int x, int y) {
	mX = x;
	mY = y;
}
void CVEHICLE::set(int x, int y) { 
	mX = x;
	mY = y;
}
int& CVEHICLE::getX() {
	return mX;
}
int& CVEHICLE::getY() {
	return mY;
}
CVEHICLE::~CVEHICLE() { }