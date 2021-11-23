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

CPEOPLE CGAME::getPeople() {
    return cn;
}
void CGAME::updatePosPeople(char input) {
    if (input == 'w')
        cn.Up(4);
    else if (input == 'a')
        cn.Left(2);
    else if (input == 'd')
        cn.Right(2);
    else if (input == 's')
        cn.Down(4);
}