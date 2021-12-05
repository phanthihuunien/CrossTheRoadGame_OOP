#include "CAMBULANCE.h"
CAMBULANCE::CAMBULANCE():CVEHICLE(), prevX(0), prevY(0) {}
CAMBULANCE::CAMBULANCE(int x, int y):CVEHICLE(x,y),prevX(0),prevY(0) {}


void CAMBULANCE::DrawLeft() {
	for (int i = 0; i < 3; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = 0; j < 4; ++j) {
			cout << ' ';
		}
	}
	gotoXY(prevX,prevY + 2);
	cout << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoXY(mX + 2, mY);cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoXY(mX, mY + 1);cout << char(220) << char(219) << char(219) << char(219);
	gotoXY(mX, mY + 2);cout << "0  0";
}

void CAMBULANCE::DrawRight() {
	for (int i = 0; i < 3; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = 0; j < 4; ++j) {
			cout << ' ';
		}
	}
	gotoXY(prevX, prevY + 2);
	cout << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoXY(mX + 1, mY);cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoXY(mX, mY + 1);	cout << char(219) << char(219) << char(219) << char(220);
	gotoXY(mX, mY + 2);cout << "0  0";

}

void CAMBULANCE::ambulanceMove(int x,int y) {
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
}