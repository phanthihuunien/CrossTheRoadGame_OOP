#pragma once
#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE {
	static int numTruck;
public:
	void Draw();
	void deleteChar();
	void increaseNumTruck();
};

