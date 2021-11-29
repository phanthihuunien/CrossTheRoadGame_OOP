#pragma once
#include"CONSOLE.h"
#include"Header.h"
class CANIMAL {
protected:
	int mX, mY;
public:
	friend class CPEOPLE;

	 void Move();
	 virtual void Draw() {}
	 virtual void deleteChar() {}

	friend class CGAME;

	virtual void Tell() = 0;
	CANIMAL();
	CANIMAL(int x, int y);
	void set(int x, int y);
	int& getX();
	int& getY();
	~CANIMAL();


};
