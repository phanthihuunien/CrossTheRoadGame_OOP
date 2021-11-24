#pragma once
#include "Header.h"
#include"CONSOLE.h"
class CVEHICLE {
protected:
	int mX, mY,prevX,prevY;
	int n=3;
	int m=4;
public:

	friend class CPEOPLE;
	virtual void Move(int, int);
	virtual void Draw();
	CVEHICLE();
	CVEHICLE(int x, int y);
	void set(int x, int y);
	int& getX();
	int& getY();
	~CVEHICLE();
};
