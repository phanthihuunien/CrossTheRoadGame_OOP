#include "CAMBULANCE.h"
CAMBULANCE::CAMBULANCE():CVEHICLE(), prevX(0), prevY(0) {}
CAMBULANCE::CAMBULANCE(int x, int y):CVEHICLE(x,y),prevX(0),prevY(0) {}


void CAMBULANCE::DrawLeft() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoXY(mX + 2, mY);cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoXY(mX, mY + 1);cout << char(220) << char(219) << char(219) << char(219);
	gotoXY(mX, mY + 2);cout << "0  0";
}
void CAMBULANCE::deleteLeftChar() {
	gotoXY(mX + 2, mY); cout << " ";
	gotoXY(mX, mY + 1); cout << " ";
	gotoXY(mX, mY + 2); cout << " ";
}
void CAMBULANCE::DrawRight() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoXY(mX + 1, mY);cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoXY(mX, mY + 1);	cout << char(219) << char(219) << char(219) << char(220);
	gotoXY(mX, mY + 2);cout << "0  0";

}
void CAMBULANCE::deleteRightChar() {
	gotoXY(mX + 1, mY); cout <<" ";
	gotoXY(mX, mY + 1);	cout << " ";
	gotoXY(mX, mY + 2); cout << " ";
}
void CAMBULANCE::ambulanceMove(int x,int y) {
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
}