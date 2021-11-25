#include"CGAME.h"
#include <string>
#include <iostream>

string stringEnd = "Dead, type y to continue or anykey to exit";

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

void CGAME::resetGame(){
	SetColor(15);
	clearGame();

	int sizeStr = stringEnd.length();
	GotoXY(WIDTH / 5 + 2, HEIGHT + 1);
	for (int i = 0; i < sizeStr; i++) cout << " ";
	CGAME* cg = new CGAME(velocity, numOfObj, isSound);
	*this = *cg;

	this->getPeople().isLive() = false;
}

void CGAME::clearGame(){
    system("cls");
    for (int i = 0; i < xhSize; i++)
		this->getCar()[i].draw("_");
	for (int i = 0; i < xtSize; i++)
		this->getTruck()[i].draw("_");

	for (int i = 0; i < klSize; i++)
		this->getDinauour()[i].draw("_");
	for (int i = 0; i < chSize; i++)
		this->getBird()[i].draw("_");

	int xCNSize = this->getPeople().getX().size();
	for (int i = 0; i < xCNSize; i++)
	if (this->getPeople().getY()[i] % 4 == 0 && this->getPeople().getY()[i] != MAXHEIGHT - 1 - i)
		this->getPeople().draw("_");
	else
		this->getPeople().draw(" ");

	for (int i = 0; i < NUM_LANE; i++)
	{
		gotoXY(this->getPeople().getX()[0], LANE[i]);
		cout << "_";
		gotoXY(this->getPeople().getX()[0], LANE[i] + 1);
		cout << " ";
	}
}

void CGAME::resetGame(){
	SET_COLOR(15);
	clearGame();

	int sizeStr = stringEnd.length();
	gotoXY(MAXWIDTH / 5 + 2, MAXHEIGHT + 1);
	for (int i = 0; i < sizeStr; i++) cout << " ";
	CGAME* cg = new CGAME();
	*this = *cg;

	this->getPeople().isLive() = false;
}