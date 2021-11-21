#pragma once
#include"CONSOLE.h"
#include"Header.h"
class CANIMAL {
protected:
	int mX, mY, prevX, prevY;
public:
	friend class CPEOPLE;
	virtual void Move(int x, int y);
	virtual void Draw();
	virtual void Tell() = 0;

};
