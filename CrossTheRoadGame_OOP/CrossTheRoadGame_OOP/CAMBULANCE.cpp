#include "CAMBULANCE.h"
CAMBULANCE::CAMBULANCE():CVEHICLE(), prevX(0), prevY(0) {}
CAMBULANCE::CAMBULANCE(int x, int y):CVEHICLE(x,y),prevX(0),prevY(0) {}


void CAMBULANCE::DrawLeft() {
	for (int i = -1; i < 2; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j =-1; j < 3; ++j) {
			cout << ' ';
		}
	}
	gotoXY(prevX,prevY + 1);
	cout << " ";
	SET_COLOR(4);
	gotoXY(mX + 2, mY-1);cout << char(254);
	SET_COLOR(7);
	gotoXY(mX, mY );cout << char(220) << char(219) << char(219) << char(219);
	gotoXY(mX, mY + 1);cout << "0  0";
}

void CAMBULANCE::DrawRight() {
	for (int i = -1; i < 2; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = -1; j < 3; ++j) {
			cout << ' ';
		}
	}
	gotoXY(prevX, prevY + 1);
	cout << " ";
	SET_COLOR(4);

	gotoXY(mX + 1, mY-1);cout << char(254);
	SET_COLOR(7);

	gotoXY(mX, mY );	cout << char(219) << char(219) << char(219) << char(220);
	gotoXY(mX, mY + 1);cout << "0  0";

}

void CAMBULANCE::ambulanceMove(int x,int y) {
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
}