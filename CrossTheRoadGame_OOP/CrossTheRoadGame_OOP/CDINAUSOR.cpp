#include"CDINAUSOR.h"
CDINAUSOR::CDINAUSOR() {}
CDINAUSOR::CDINAUSOR(int x, int y) {}

void CDINAUSOR::Draw() {
	CANIMAL::Draw();
	gotoXY(mX, mY);	   cout << "  \\_\\";
	gotoXY(mX, mY + 1);cout << " _/ ^_)";
	gotoXY(mX, mY + 2);cout << "  U  U";
}
void CDINAUSOR::Tell() {
	PlaySound(L"dinotell.wav", NULL, SND_SYNC);
}