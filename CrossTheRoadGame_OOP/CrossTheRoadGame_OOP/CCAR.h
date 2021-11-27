#pragma once
#include"CVEHICLE.h"
class CCAR : public CVEHICLE {
    static int numCar;
public:
    CCAR();
    CCAR(int x, int y);
	void Draw();
    void deleteChar();
    void increaseNumCar();
};  

