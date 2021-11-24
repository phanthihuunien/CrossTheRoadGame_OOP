#include"CBIRD.h"
CBIRD::CBIRD() :CANIMAL() {}
CBIRD::CBIRD(int x, int y):CANIMAL(x,y) {}

void CBIRD::Draw() {
	CANIMAL::Draw();
	gotoXY(mX, mY);cout << "<@__";
	gotoXY(mX, mY + 1);cout << "(_-/";
	gotoXY(mX, mY + 2);cout << " \\ \\";

}
void CBIRD::Tell() {
	PlaySound(L"birdtell.wav", NULL, SND_SYNC);
}