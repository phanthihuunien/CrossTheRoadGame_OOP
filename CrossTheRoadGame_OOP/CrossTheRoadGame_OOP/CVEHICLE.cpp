#include "CVEHICLE.h"
#include <iostream>
using namespace std;

CVEHICLE::CVEHICLE(): mX(0), mY(0), prevX(0), prevY(0) {};

void CVEHICLE::Move(int x,int y ){
    mX=x;
    mY=y;
    prevX=mX;
    prevY=mY;
}