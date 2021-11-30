#include"CDINAUSOR.h"
CDINAUSOR::CDINAUSOR():CANIMAL() {}
CDINAUSOR::CDINAUSOR(int x, int y):CANIMAL(x,y) {}

void CDINAUSOR::Draw() {
	SET_COLOR(4);	
	gotoXY(mX - 1, mY); cout << char(220);
	gotoXY(mX, mY);cout<<char(219);
	gotoXY(mX + 1, mY - 1); cout << char(220);
	gotoXY(mX + 1, mY); cout << char(223);
	SET_COLOR(0);
}
void CDINAUSOR::deleteChar() {
	gotoXY(mX - 1, mY); cout << ' ';
	gotoXY(mX, mY); cout <<' ';
	gotoXY(mX + 1, mY - 1); cout << ' ';
	gotoXY(mX + 1, mY); cout << ' ';
}
void CDINAUSOR::Tell() {
	PlaySound(L"dinotell.wav", NULL, SND_SYNC);
}