#pragma once
#include"CANIMAL.h"
class CBIRD : public CANIMAL {
public:
	void Draw();
	void deleteChar();
	void Tell();
	CBIRD();
	CBIRD(int x, int y);
};
