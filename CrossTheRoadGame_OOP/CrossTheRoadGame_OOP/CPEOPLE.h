﻿#pragma once

#include"CVEHICLE.h"
#include"CANIMAL.h"

class CPEOPLE {
private:
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

