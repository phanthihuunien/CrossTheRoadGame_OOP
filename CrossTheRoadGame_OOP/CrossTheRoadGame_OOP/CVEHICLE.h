#pragma once
class CVEHICLE {
	int mX, mY;
public:

	friend class CPEOPLE;
	virtual void Move(int, int);
	//…
};
