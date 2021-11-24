#pragma once
#include"CVEHICLE.h"
class CCAR : public CVEHICLE {
    static int numCar;
public:
	void Draw();
    void deleteChar();
    void increaseNumCar();
};

