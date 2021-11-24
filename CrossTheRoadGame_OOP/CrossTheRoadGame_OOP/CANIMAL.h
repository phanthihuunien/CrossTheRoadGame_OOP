#pragma once
#include"CONSOLE.h"
#include"Header.h"
class CANIMAL {
protected:
	int mX, mY;
public:
	friend class CPEOPLE;
	virtual void Move();
	virtual void Draw();
	virtual void Tell() = 0;
	CANIMAL();
	CANIMAL(int x, int y);
	void set(int x, int y);
	int& getX();
	int& getY();
	~CANIMAL();


};
