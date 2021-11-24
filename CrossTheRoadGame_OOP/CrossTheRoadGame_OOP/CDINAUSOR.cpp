#include"CDINAUSOR.h"
CDINAUSOR::CDINAUSOR() {}
CDINAUSOR::CDINAUSOR(int x, int y) {}

void CDINAUSOR::Draw() {
	gotoXY(mX + 1, mY - 1); cout << char(220);
	gotoXY(mX + 1, mY);cout<< char(223);
	gotoXY(mX, mY);cout<<(219);
	gotoXY(mX - 1, mY);cout<<char(220);
}
void CDINAUSOR::deleteChar() {
	gotoXY(mX + 1, mY - 1); cout <<' ';
	gotoXY(mX + 1, mY); cout << ' ';
	gotoXY(mX, mY); cout <<' ';
	gotoXY(mX - 1, mY); cout <<' ';
}
void CDINAUSOR::Tell() {
	PlaySound(L"dinotell.wav", NULL, SND_SYNC);
}