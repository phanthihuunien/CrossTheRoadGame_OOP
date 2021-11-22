#include "CVEHICLE.h"
#include "CONSOLE.h"
#include <iostream>
using namespace std;

CVEHICLE::CVEHICLE(): mX(0), mY(0), prevX(0), prevY(0) {};

void CVEHICLE::Move(int x,int y ){
    mX=x;
    mY=y;
    prevX=mX;
    prevY=mY;
}

void CVEHICLE::Draw() {
	for (int i = 0; i < n; ++i) {
		gotoXY(prevX, prevY + i);
		for (int j = 0; j < m; ++j) {
			cout << ' ';
		}
	}
};