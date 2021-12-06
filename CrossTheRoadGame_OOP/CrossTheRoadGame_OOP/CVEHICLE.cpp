#include "CVEHICLE.h"
#include "CONSOLE.h"
#include "Header.h"

void CVEHICLE::Move(){
	srand((int)time(0));
	if (lv < 5) {
		mX -= 1+ rand() % 3;
	}
	else mX -= lv - rand() % 3 + 1;
	if (mX <= 2)
	{
		mX = MAXWIDTH - 2;
	}
}

void CVEHICLE::Erase() {
	for (int i = 0; i < 3; ++i) {
		gotoXY(mX, mY + i);
		for (int j = 0; j < 4; ++j) {
			cout << ' ';
		}
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