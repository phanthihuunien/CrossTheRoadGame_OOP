#pragma once
#include"CVEHICLE.h"
class CAMBULANCE:public CVEHICLE
{
	int prevX, prevY;
public:
	CAMBULANCE();
	CAMBULANCE(int x, int y);
	CAMBULANCE(int prevX, int prevY);

	void ambulanceMove(int x, int y);
	void DrawLeft();
	void deleteLeftChar();
	void DrawRight();
	void deleteRightChar();
	

};

