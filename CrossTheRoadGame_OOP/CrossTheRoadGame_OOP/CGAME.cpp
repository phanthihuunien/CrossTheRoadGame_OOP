#include"CGAME.h"

CGAME::CGAME()
{
    int level = getPeople(). getLevel();
    axt = new CTRUCK[level];
    axh = new CCAR[level];
    akl = new CDINAUSOR[level];
    ac = new CBIRD[level ];
    for (int i = 0; i <level ; i++) {
        int x_animal = MAXWIDTH - 11 * i - 5;
        int x_vehical = 11 * i + 5;
        ac[i].set(x_animal, y_bird);
        akl[i].set(x_animal, y_dinausor);
        axt[i].set(x_vehical, y_truck);
        axh[i].set(x_vehical, y_car);
    }
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
CTRUCK* CGAME::getTruck() {
    return axt;
}
CCAR* CGAME::getCar() {
    return axh;
}
CBIRD* CGAME::getBird() {
    return ac;
}
CDINAUSOR* CGAME::getDinausor() {
    return akl;
}
void CGAME::updatePosAnimal() {
    int level = getPeople().getLevel();
    for (int i = 0; i < level; i++) {
        ac[i].Move();
        ac[i].Draw();
    }
    for (int i = 0; i < level; i++) {
        akl[i].Move();
        akl[i].Draw();
    }
}
CGAME::~CGAME()
{
    delete[]axt;
    delete[]axh;
    delete[]akl;
    delete[]ac;
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