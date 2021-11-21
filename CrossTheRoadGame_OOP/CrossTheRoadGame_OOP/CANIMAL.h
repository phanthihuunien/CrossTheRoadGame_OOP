#pragma once
class CANIMAL {
private:
	int mX, mY;
public:
	friend class CPEOPLE;
	virtual void Move(int, int);
	virtual void Tell();
};
