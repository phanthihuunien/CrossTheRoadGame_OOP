#include "CVEHICLE.h"
#include "CONSOLE.h"
#include "Header.h"
#include <iostream>
using namespace std;

void CVEHICLE::Move(int x,int y ){
    mX=x;
    mY=y;
    prevX=mX;
    prevY=mY;
}

void CVEHICLE::Draw() {
	for (int i = 0; i < START_X; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = 0; j < START_Y; ++j) {
			cout << ' ';
		}
	}
};

CVEHICLE::CVEHICLE() {
	mX = 0;
	mY = 0;
}
CVEHICLE::CVEHICLE(int x, int y) {
	mX = x;
	mY = y;
}
void CVEHICLE::set(int x, int y) { 
	mX = x;
	mY = y;
}
int& CVEHICLE::getX() {
	return mX;
}
int& CVEHICLE::getY() {
	return mY;
}
CVEHICLE::~CVEHICLE() { }