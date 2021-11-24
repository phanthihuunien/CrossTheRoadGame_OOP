#include"CGAME.h"

CGAME::CGAME()
{
}

void CGAME::drawBackground() {
    int W = 130;
    int H = 25;
    SET_COLOR(7);
    for (int i = 0; i < H; i++) {
        for (int j = 2; j < W + 1; j++) {
            cout << (char)219;
            if (j == W || j == 2) {
                gotoXY(j, i);
                wcout << "|";
            }
            else if (i == H - 1 || i % 4 == 0) {
                gotoXY(j, i);
                wcout << "-";
            }
        }
    }
}

CGAME::~CGAME()
{
}


void CGAME::startGame(){
	system("cls");
	DrawBoard(0, 0, MAXWIDTH, MAXHEIGHT);
	this->drawBackground();

	gotoXY(MAXWIDTH / 6 + 2, MAXHEIGHT + 3);
	cout << "SAVE (L)";
	gotoXY(MAXWIDTH / 6 * 2 + 2, MAXHEIGHT + 3);
	cout << "LOAD (T)";
	gotoXY(MAXWIDTH / 6 * 3 + 2, MAXHEIGHT + 3);
	cout << "EXIT (ESC)";
	gotoXY(MAXWIDTH / 6 * 4 + 2, MAXHEIGHT + 3);
	cout << "PAUSE (P) ";

	this->getPeople().isLive() = true;
}

