#pragma once
#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE {
	static int numTruck;
public:
	CTRUCK();
	CTRUCK(int x, int y);
	void Draw();
	void deleteChar();
	void increaseNumTruck();
};

