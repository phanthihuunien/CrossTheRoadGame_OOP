#include"CGAME.h"

string stringEnd = "Dead, type y to continue or anykey to exit";

CGAME::CGAME()
{
	int level = getPeople().getLevel();
	axt = new CTRUCK[level];
	axh = new CCAR[level];
	akl = new CDINAUSOR[level];
	ac = new CBIRD[level];
    ani = new CANIMAL*[2];
    veh = new CVEHICLE*[2];
    ani[0] = akl;
    ani[1] = ac;
    veh[0] = axt;
    veh[1] = axh;
	for (int i = 0; i < level; i++) {
		int x_animal = MAXWIDTH - 11 * i - 5;
		int x_vehical = 11 * i + 5;
		ac[i].set(x_animal, y_bird);
		akl[i].set(x_animal, y_dinausor);
		axt[i].set(x_vehical, y_truck);
		axh[i].set(x_vehical, y_car);
	}
}

void CGAME::updateObstacle()
{
    for (int i = 0; i < getPeople().getLevel(); ++i) {
        int x_animal = MAXWIDTH - 11 * i - 5;
        int x_vehical = 11 * i + 5;
        ac[i].set(x_animal, y_bird);
        akl[i].set(x_animal, y_dinausor);
        axt[i].set(x_vehical, y_truck);
        axh[i].set(x_vehical, y_car);
    }
}
void CGAME::drawGame()
{
	if (dxt.getLight()) {
		SET_COLOR(2);
		gotoXY(MAXWIDTH + 1, 17);
		cout << char(254);
		SET_COLOR(8);
	}
	else if (!dxt.getLight()) {
		SET_COLOR(4);
		gotoXY(MAXWIDTH + 1, 18);
		cout << char(254);
		SET_COLOR(8);
	}
	if (dxh.getLight()) {
		SET_COLOR(2);
		gotoXY(1, 13);
		cout << char(254);
		SET_COLOR(8);
	}
	else if (!dxh.getLight()) {
		SET_COLOR(4);
		gotoXY(1, 14);
		cout << char(254);
		SET_COLOR(8);
	}
	for (int i = 0; i < cn.getLevel(); i++) {
		axt[i].Draw();
		axh[i].Draw();
		ac[i].Draw();
		akl[i].Draw();
	}
}

void CGAME::drawBackground() {
	system("color 80");
	for (int i = 0; i < MAXHEIGHT; i++) {
		for (int j = 2; j < MAXWIDTH + 1; j++) {
            SET_COLOR(8);
            cout << (char)219;
            if (j == MAXWIDTH || j == 2) {
				gotoXY(j, i);
				cout << "|";
			}
			else if (i == MAXHEIGHT - 1 || i % 4 == 0) {
				if (j % 4 == 0) {
					SET_COLOR(7);
					gotoXY(j, i);
					cout << (char)219;
					cout << (char)219;
					cout << (char)219;

				}
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
CANIMAL** CGAME::getAnimal()
{
    return ani;
}
CVEHICLE** CGAME::getVehicle()
{
    return veh;
}
CTRAFFICLIGHT& CGAME::getCarLight()
{
    return dxh;
}
CTRAFFICLIGHT& CGAME::getTruckLight()
{
    return dxt;
}
void CGAME::updateLevel()
{
    gotoXY(28, 30);
    cout << "        ";
    gotoXY(28, 30);
    cout << "LEVEL " << getPeople().getLevel();
}
bool CGAME::askRestart(mutex& mx)
{
    int boxWidth = 42, boxHeight = 4, startBoxX = 44, startBoxY = 32;
    lock_guard<mutex> lock(mx);

    gotoXY(startBoxX, startBoxY);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    gotoXY(startBoxX, startBoxY + 1);
    for (int j = 0; j < boxWidth; ++j) {
        if (j == 0 || j == boxWidth - 1)
            cout << '|';
        else
            cout << ' ';
    }

    gotoXY(startBoxX, startBoxY + 2);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }

    string line2 = "Do you want to restart the game? (y/n)";
    gotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1);
    cout << line2;

    char answer;
    while (true) {
        answer = _getch();
        if (answer == 'y' || answer == 'n')
            break;
    }
    if (answer == 'y')
        return true;
    else
        return false;

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

CPEOPLE CGAME::getPeople()
{
	return cn;
}



void CGAME::startGame(thread& t1) {
	system("cls");
	drawBackground();

	gotoXY(MAXWIDTH / 6 + 2, MAXHEIGHT + 2);
	cout << "SAVE (L)";
	gotoXY(MAXWIDTH / 6 * 2 + 2, MAXHEIGHT + 2);
	cout << "LOAD (T)";
	gotoXY(MAXWIDTH / 6 * 3 + 2, MAXHEIGHT + 2);
	cout << "EXIT (ESC)";
	gotoXY(MAXWIDTH / 6 * 4 + 2, MAXHEIGHT + 2);
	cout << "PAUSE (P) ";
	
    if (t1.joinable())
        t1.join();
    t1 = thread(SubThread);
}

void CGAME::resetGame() {
    system("cls");
    drawBackground();
    updateObstacle();
    cn.getY() = 21;
}
void CGAME::resetData(){
	SET_COLOR(15);
	//clearGame();

	int sizeStr = stringEnd.length();
	gotoXY(MAXWIDTH / 5 + 2, MAXHEIGHT + 1);
	for (int i = 0; i < sizeStr; i++) cout << " ";
	CGAME* cg = new CGAME;
	*this = *cg;
}
void CGAME::exitGame(thread*t1, bool&IS_RUNNING)
{
    IS_RUNNING = false;
    Sleep(500);
    if (t1->joinable())
        t1->join();
    system("cls");
}
//
//void CGAME::clearGame(){
//    system("cls");
//    for (int i = 0; i < carSize; i++)
//		this->getCar()[i].draw("_");
//	for (int i = 0; i < truckSize; i++)
//		this->getTruck()[i].draw("_");
//
//	for (int i = 0; i < dinausorSize; i++)
//		this->getDinauour()[i].draw("_");
//	for (int i = 0; i < birdSize; i++)
//		this->getBird()[i].draw("_");
//
//	int xCNSize = this->getPeople().getX().size();
//	for (int i = 0; i < xCNSize; i++)
//	if (this->getPeople().getY()[i] % 4 == 0 && this->getPeople().getY()[i] != MAXHEIGHT - 1 - i)
//		this->getPeople().draw("_");
//	else
//		this->getPeople().draw(" ");
//
//	for (int i = 0; i < numLane; i++)
//	{
//		gotoXY(this->getPeople().getX()[0], LANE[i]);
//		cout << "_";
//		gotoXY(this->getPeople().getX()[0], LANE[i] + 1);
//		cout << " ";
//	}
//}
//


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
void CGAME::clearMessage(int x, int y, int length) {
    gotoXY(x, y);
    for (int i = 0; i < length; ++i) {
        cout << ' ';
    }
}
bool CGAME::checkFileExist(const string& fileName) {
    struct stat buffer;
    return stat(fileName.c_str(), &buffer) == 0;
}
void CGAME::writeFile(std::ostream& stream, int x) {
    stream.write((char*)&x, sizeof(int));
}
int CGAME::readFile(ifstream& stream)
{
    int x;
    stream.read((char*)&x, sizeof(int));
    return x;
}
bool CGAME::saveGame(mutex& mx, bool inMenu) {

    lock_guard<mutex> lock(mx);
    int boxWidth = 62, boxHeight = 4, startBoxX = 0, startBoxY = 32;
    gotoXY(startBoxX, startBoxY);
    SET_COLOR(12);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    gotoXY(startBoxX, startBoxY + 1);
    cout << '#';
    gotoXY(startBoxX, startBoxY + 2);
    cout << '#';
    gotoXY(boxWidth - 1, startBoxY + 1);
    cout << '#';
    gotoXY(boxWidth - 1, startBoxY + 2);
    cout << '#';

    gotoXY(startBoxX, startBoxY + 3);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    SET_COLOR(10);
    string message = "Enter the name to save the game: ", fileName;
    gotoXY(startBoxX + (boxWidth - message.size()) / 2, startBoxY + 1);
    cout << message;

    if (!inMenu)
        gotoXY(1, startBoxY + 2);
    SET_COLOR(7);
    while (true) {

        cin >> fileName;
        GetAsyncKeyState(VK_RETURN); //Enter
        clearMessage(startBoxX + (boxWidth - message.size()) / 2, startBoxY + 2, message.size());
        
        if (checkFileExist(fileName)) {
           
            SET_COLOR(11);
            string message2 = "The filename already exists!!. Do you want to overwrite it?\n (1. Yes, 0. No): ";
            gotoXY(startBoxX , startBoxY + 1);
            
            cout << message2;
            int ans;
            gotoXY(startBoxX + boxWidth / 3, startBoxY + 2);
            ans = _getch();
            if (ans == 0) {
                clearMessage(startBoxX, startBoxY + 1, boxWidth - 2);
                clearMessage(startBoxX, startBoxY + 2, boxWidth - 2);
                SET_COLOR(14);
                string message3 = "Enter another file name: ";
                gotoXY(startBoxX + (boxWidth - message3.size()) / 2, startBoxY + 1);
                cout << message3;
                gotoXY(startBoxX + (boxWidth - message3.size()) + 6, startBoxY + 1);
                SET_COLOR(7);
               
                continue;
            }
        }
        ofstream fileOut(fileName, ios::out | ios::binary);
        // save mX and mY of people
        writeFile(fileOut, getPeople().mX);
        writeFile(fileOut, getPeople().mY);

        writeFile(fileOut, getPeople().getLevel());
        for (int i = 0; i < getPeople().getLevel(); ++i) {
            writeFile(fileOut, axt[i].mX);
            writeFile(fileOut, axt[i].mY);
        }

        for (int i = 0; i < getPeople().getLevel(); ++i) {
            writeFile(fileOut, axh[i].mX);
            writeFile(fileOut, axh[i].mY);
        }

        for (int i = 0; i < getPeople().getLevel(); ++i) {
            writeFile(fileOut, akl[i].mX);
            writeFile(fileOut, akl[i].mY);
        }

        for (int i = 0; i < getPeople().getLevel(); ++i) {
            writeFile(fileOut, ac[i].mX);
            writeFile(fileOut, ac[i].mY);
        }
        fileOut.close();
        break;
    }

    for (int i = 1; i < 3; ++i) {
        clearMessage(startBoxX, startBoxY + i, boxWidth - 1);
    }

    string message4 = "Do you want to exit the game? (1. Yes, 0. No) ";
    gotoXY(startBoxX + 4 , startBoxY + 1);
    cout << message4;

    gotoXY(startBoxX + 6 , startBoxY + 1);
    int c = _getch();
    for (int i = 0; i < 4; ++i) {
        clearMessage(startBoxX, startBoxY + i, boxWidth);
    }
    if (c == 1) return true;
    return false;
}

void CGAME::pauseGame(thread&t1)
{
    SuspendThread(t1.native_handle());
}

void CGAME::resumeGame(thread&t1)
{
    ResumeThread(t1.native_handle());
}

void CGAME::loadGame(mutex& mx, bool inMenu)
{
    lock_guard<mutex> lock(mx);
    int boxWidth = 62, boxHeight = 4, startBoxX = 0, startBoxY = 32;

    gotoXY(startBoxX, startBoxY);
    SET_COLOR(12);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    gotoXY(startBoxX, startBoxY + 1);
    cout << '#';
    gotoXY(startBoxX, startBoxY + 2);
    cout << '#';
    gotoXY(boxWidth - 1, startBoxY + 1);
    cout << '#';
    gotoXY(boxWidth - 1, startBoxY + 2);
    cout << '#';

    gotoXY(startBoxX, startBoxY + 3);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    SET_COLOR(10);
    string message = "Enter the name to save the game: ", fileName;
    gotoXY(startBoxX + (boxWidth - message.size()) / 2, startBoxY + 1);
    cout << message;

    if (!inMenu)
        gotoXY(1, startBoxY + 2);
    SET_COLOR(7);
    while (true) {

        cin >> fileName;
        GetAsyncKeyState(VK_RETURN); //Enter
        clearMessage(startBoxX + (boxWidth - message.size()) / 2, startBoxY + 2, message.size());

        if (checkFileExist(fileName)) {

            SET_COLOR(11);
            string message2 = "File do not exists. Do you want to cancel?\n (1. Yes, 0. No): ";
            gotoXY(startBoxX, startBoxY + 1);

            cout << message2;
            int ans;
            gotoXY(startBoxX + boxWidth / 3, startBoxY + 2);
            ans = _getch();
            if (ans == 0) {
                clearMessage(startBoxX, startBoxY + 1, boxWidth - 2);
                clearMessage(startBoxX, startBoxY + 2, boxWidth - 2);
                SET_COLOR(14);
                string message3 = "Enter another file name: ";
                gotoXY(startBoxX + (boxWidth - message3.size()) / 2, startBoxY + 1);
                cout << message3;
                gotoXY(startBoxX + (boxWidth - message3.size()) + 6, startBoxY + 1);
                SET_COLOR(7);
                continue;
            }
        }
        ifstream fin(fileName, ios::out | ios::binary);
		// player
        getPeople().getX() = readFile(fin);
        getPeople().getY() = readFile(fin);
		// level
        getPeople().getLevel() = readFile(fin);
		// trucks
		for (int i = 0; i < getPeople().getLevel(); ++i) {
			axt[i].mX = readFile(fin);
			axt[i].mY = readFile(fin);
		}

		// cars
		for (int i = 0; i < getPeople().getLevel(); ++i) {
			axh[i].mX = readFile(fin);
			axh[i].mY = readFile(fin);
		}

		// dinos
		for (int i = 0; i < getPeople().getLevel(); ++i) {
			akl[i].mX = readFile(fin);
			akl[i].mY = readFile(fin);
		}

		// birds
		for (int i = 0; i < getPeople().getLevel(); ++i) {
			ac[i].mX = readFile(fin);
			ac[i].mY = readFile(fin);
		}
        fin.close();
		system("cls");
		drawBackground();
		break;
	}
}
void CGAME::ambulanceEffect(mutex& mx) {
    lock_guard<mutex> lock(mx);
    if (cn.getY() == 18) {
        for (int i = 0; i < getPeople().getLevel(); ++i)
            axt[i].CVEHICLE::deleteChar();
    }else if (cn.getY() == 14) {
        for (int i = 0; i < getPeople().getLevel(); ++i)
            axh[i].CVEHICLE::deleteChar();
    }
    else if (cn.getY() == 10) {
        for (int i = 0; i < getPeople().getLevel(); ++i)
            akl[i].CANIMAL::deleteChar();
    }
    else if (cn.getY() == 6) {
        for (int i = 0; i < getPeople().getLevel(); ++i)
            ac[i].CANIMAL::deleteChar();
    }
    gotoXY(getPeople().getX(), getPeople().getY()); cout << "\\ /";
    gotoXY(getPeople().getX(), getPeople().getY() + 1);cout << " X ";
    gotoXY(getPeople().getX(), getPeople().getY() + 2);cout << "/"<< " " << "\\";

    if (cn.getX() > MAXWIDTH / 2) {
        CAMBULANCE ambulance(3, cn.getY());
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX + 5 >= cn.getX()) {
                ambulance.ambulanceMove(ambulance.mX, ambulance.mY);
            }
            else {
                ambulance.ambulanceMove(ambulance.mX + 2, ambulance.mY);
            }
            ambulance.DrawRight();
            Sleep(50);
        }
        cn.eraseOldPeople();
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX <= 5) {
                gotoXY(ambulance.mX, cn.getY());cout << "    ";
                gotoXY(ambulance.mX, cn.getY() + 1);cout << "    ";
                gotoXY(ambulance.mX, cn.getY() + 2); cout << "    ";
            }
            else {
                ambulance.ambulanceMove(ambulance.mX - 2, ambulance.mY);
                ambulance.DrawLeft();
            }
            Sleep(50);
        }
    }
    else if (cn.getX() < MAXWIDTH / 2) {
        CAMBULANCE ambulance(MAXWIDTH - 4, cn.getY());
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX <= cn.getX() + 5) {
                ambulance.ambulanceMove(ambulance.mX, ambulance.mY);
            }
            else {
                ambulance.ambulanceMove(ambulance.mX - 2, ambulance.mY);
            }
            ambulance.DrawLeft();
            Sleep(50);
        }
        cn.eraseOldPeople();
        for (int i = 0; i < 50; i++) {
            if (ambulance.mX + 5 >= MAXWIDTH) {
                gotoXY(ambulance.mX, cn.getY());cout << "    ";
                gotoXY(ambulance.mX, cn.getY() + 1);cout << "    ";
                gotoXY(ambulance.mX, cn.getY() + 2);cout << "    ";
            }
            else {
                ambulance.ambulanceMove(ambulance.mX + 2, ambulance.mY);
                ambulance.DrawRight();
            }
            Sleep(50);
        }
    }
}
void CGAME::ambulanceSound(mutex& mx) {
    PlaySound(L"ambulance.wav", NULL, SND_FILENAME);
}