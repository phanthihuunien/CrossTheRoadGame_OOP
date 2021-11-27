#include"CBIRD.h"
CBIRD::CBIRD():CANIMAL() {}
CBIRD::CBIRD(int x, int y):CANIMAL(x,y) {}

void CBIRD::Draw() {
	SET_COLOR(3);
	gotoXY(mX, mY); cout << char(219);
	gotoXY(mX - 1, mY - 1); cout << char(219);
	gotoXY(mX + 1, mY - 1); cout << char(219);

}
void CBIRD::deleteChar() {
	gotoXY(mX, mY);
	cout << ' ';
	gotoXY(mX - 1, mY - 1);
	cout << ' ';
	gotoXY(mX + 1, mY - 1);
	cout << ' ';

}
void CBIRD::Tell() {
	PlaySound(L"birdtell.wav", NULL, SND_SYNC);
}