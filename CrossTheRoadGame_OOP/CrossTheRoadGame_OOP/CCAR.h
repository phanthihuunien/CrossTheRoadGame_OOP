#pragma once
#include"CVEHICLE.h"
class CCAR : public CVEHICLE {
    int numCar=5;
public:
	void Draw();
    void deleteChar();
    void increaseNumCar();
};

