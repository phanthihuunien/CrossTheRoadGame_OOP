#pragma once
#include "Header.h"
class CVEHICLE {
protected:
	int mX, mY,prevX,prevY;
	int n=3;
	int m=4;
public:

	friend class CPEOPLE;
	virtual void Move(int, int);
	virtual void Draw();
	//�
};
