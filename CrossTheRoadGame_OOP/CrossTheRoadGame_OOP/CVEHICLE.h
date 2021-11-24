#pragma once
#include "Header.h"
class CVEHICLE {
protected:
	int mX, mY,prevX,prevY;
public:

	friend class CPEOPLE;
	virtual void Move(int, int);
	virtual void Draw();
	//�
};
