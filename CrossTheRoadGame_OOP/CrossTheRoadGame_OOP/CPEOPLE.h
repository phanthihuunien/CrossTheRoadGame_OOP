#pragma once

#include"CVEHICLE.h"
#include"CANIMAL.h"
#include"CONSOLE.h"
class CPEOPLE {
private:
	int mX, mY, tmpX, tmpY;
	bool mState; //Trạng thái sống chết
	int score;
	int level;
public:
	friend class CGAME;
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpactV( CVEHICLE* const&);
	bool isImpactA( CANIMAL* const&);
	bool isFinish();
	bool isLive();
	bool isDead();
	void DrawPLayer();
	//void Move(int key)
	int& getLevel();
	int getScore();
	void LevelUp();

	int& getX();
	int& getY();

	void soundCar();
	void soundTruck();

	void setAlive();
	void eraseOldPeople();
};

