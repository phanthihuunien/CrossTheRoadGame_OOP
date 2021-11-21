#include"CANIMAL.h"
void CANIMAL::Move(int x, int y)
{
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
};

void CANIMAL::Draw() {
	for (int i = 0; i < START_X; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = 0; j < START_Y; ++j) {
			cout << ' ';
		}
	}
};
