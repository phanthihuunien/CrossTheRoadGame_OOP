#include"CANIMAL.h"
CANIMAL::CANIMAL() {
	mX = 0;
	mY = 0;
}
CANIMAL::CANIMAL(int x, int y) {
	mX = x;
	mY = y;
}
void CANIMAL::set(int x, int y) {
	mX = x;
	mY = y;
}
int& CANIMAL::getX() {
	return mX;
}
int& CANIMAL::getY() {
	return mY;
}
CANIMAL::~CANIMAL() {}

void CANIMAL::Move()
{
	mX++;
	if (mX == MAXWIDTH - 2)
	{
		mX = 3;
	}
};
void CANIMAL::Erase() {
	for (int i = 0; i < 3; ++i) {
		gotoXY(mX, mY + i);
		for (int j = 0; j < 4; ++j) {
			cout << ' ';
		}
	}
}

