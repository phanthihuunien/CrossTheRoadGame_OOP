#pragma once
#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE {
	 int numTruck =5;
public:
	CTRUCK();
	CTRUCK(int x, int y);
	void Draw();
	void deleteChar();
	void increaseNumTruck();
};

