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
        ac[i].deleteChar();
        ac[i].Move();
    }
    for (int i = 0; i < level; i++) {
        akl[i].deleteChar();
        akl[i].Move();
    }
}
void CGAME::updatePosVehicle() {
    int level = getPeople().getLevel();
    for (int i = 0; i < level; i++) {
        axt[i].deleteChar();
        axt[i].Move();
    }
    for (int i = 0; i < level; i++) {
        axh[i].deleteChar();
        axh[i].Move();
    }
}
CGAME::~CGAME()
{
    delete[]axt;
    delete[]axh;
    delete[]akl;
    delete[]ac;
}

void CGAME::drawLane()
{
	for (int i = 1; i < MAXWIDTH; i++)
	for (int j = 1; j < MAXHEIGHT; j++){
		if (j % 4 == 0)
		{
			if (j != MAXHEIGHT - 1)
			{
				gotoXY(i, j);
				cout << "_";
			}
		}
	}
}

void CGAME::startGame(){
	system("cls");
	DrawBoard(0, 0, MAXWIDTH, MAXHEIGHT);
	this->drawLane();

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

