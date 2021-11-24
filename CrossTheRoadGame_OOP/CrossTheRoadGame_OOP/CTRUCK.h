#pragma once
#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE {
	 int numTruck =5;
public:
	void Draw();
	void deleteChar();
	void increaseNumTruck();
};

