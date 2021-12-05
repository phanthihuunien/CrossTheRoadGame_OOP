#pragma once
#include "Header.h"
#include"CONSOLE.h"
class CVEHICLE {
protected:
	int mX, mY;
public:
	friend class CGAME;
	friend class CPEOPLE;
	 void Move();
	 virtual void Draw() {}
	 virtual void deleteChar(){}
	 void Erase();
	CVEHICLE();
	CVEHICLE(int x, int y);
	void set(int x, int y);
	int& getX();
	int& getY();
	~CVEHICLE();
};
