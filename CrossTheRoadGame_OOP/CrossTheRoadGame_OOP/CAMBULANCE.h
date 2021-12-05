#pragma once
#include"CVEHICLE.h"
class CAMBULANCE:public CVEHICLE
{
	int prevX, prevY;
public:
	CAMBULANCE();
	CAMBULANCE(int x, int y);

	void ambulanceMove(int x, int y);
	void DrawLeft();
	void DrawRight();
	
	

};

