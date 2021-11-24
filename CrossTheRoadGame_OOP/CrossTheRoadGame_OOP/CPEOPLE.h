#pragma once

#include"CVEHICLE.h"
#include"CANIMAL.h"
#include"CONSOLE.h"
class CPEOPLE {
private:
	int mX, mY;
	bool mState; //Trạng thái sống chết
	int score;
	int level;
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpactV(const CVEHICLE*&);
	bool isImpactA(const CANIMAL*&);
	bool isFinish();
	bool isLive();
	bool isDead();
	void DrawPLayer();
	//void Move(int key)
	int getLevel();
	int getScore();
	void LevelUp();

	void soundCar();
	void soundTruck();
};

