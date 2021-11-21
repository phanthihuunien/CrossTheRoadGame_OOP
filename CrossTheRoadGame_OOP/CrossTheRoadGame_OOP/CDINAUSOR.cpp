#include"CDINAUSOR.h"
void CDINAUSOR::Draw() {
	CANIMAL::Draw();
	gotoXY(mX, mY);	   cout << "  ______/";
	gotoXY(mX, mY + 1);cout << "  |    |>>" ;
	gotoXY(mX, mY + 2);cout << " #|_/\_|";
}
void CDINAUSOR::Tell() {
	PlaySound(L"dinotell.wav", NULL, SND_SYNC);
}