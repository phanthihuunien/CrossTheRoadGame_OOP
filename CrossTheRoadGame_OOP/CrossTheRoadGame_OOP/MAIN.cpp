#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<random>
#include<chrono>
#include"CGAME.h"
#include"CONSOLE.h"

using namespace std;

char MOVING;
bool IS_RUNNING = true;
CGAME cg;
chrono::steady_clock sc;
mutex mx;
int level = 1;
bool backToMainMenu = false;
int temp = ' ';

void SubThread()
{
	int preLevel = 10;
	int templv = 10;
	cg.drawBackground();
	auto sTruck = sc.now();
	auto sCar = sc.now();
	while (IS_RUNNING) {
		// functions to simulate traffic lights
		auto eTruck = sc.now();
		auto eCar = sc.now();
		auto elapsedTruck = static_cast<chrono::duration<double>>(eTruck - sTruck);
		auto elapsedCar = static_cast<chrono::duration<double>>(eCar - sCar);

		if (templv < cg.getPeople().getLevel())
		{
			sCar = eCar;
			sTruck = eTruck;
		}
		else
		{
			if (int(elapsedTruck.count()) < 3)
				cg.getTruckLight().setLight(true);
			else if (int(elapsedTruck.count()) > 3 && int(elapsedTruck.count()) < 5)
				cg.getTruckLight().setLight(false);
			else if (int(elapsedTruck.count()) >7 )
				sTruck = eTruck;
			if (int(elapsedCar.count()) < 4)
				cg.getCarLight().setLight(true);
			else if (int(elapsedCar.count()) > 4 && int(elapsedCar.count()) < 8)
				cg.getCarLight().setLight(false);
			else if (int(elapsedCar.count()) > 8)
				sCar = eCar;
		}
		templv = cg.getPeople().getLevel();

		bool hitSth = false;
		if (cg.getPeople().isImpactA(cg.getAnimal()[0])) {
			cg.getAnimal()[0]->Tell();
			hitSth = true;
		}
		if (cg.getPeople().isImpactA(cg.getAnimal()[1])) {
			cg.getAnimal()[1]->Tell();
			hitSth = true;
		}
		if (cg.getPeople().isImpactV(cg.getVehicle()[0])) {
			cg.getPeople().soundTruck();
			hitSth = true;
		}
		if (cg.getPeople().isImpactV(cg.getVehicle()[1])) {
			cg.getPeople().soundCar();
			hitSth = true;
		}
		if (hitSth) {
			cg.getPeople().setDead();
			cg.ambulanceSound(mx);
			cg.ambulanceEffect(mx);
			break;
		}
		cg.updateLevel();
		lv = cg.getPeople().getLevel();

		if (!cg.getPeople().isDead())
		{
			if (MOVING != ' ')
		
				cg.updatePosPeople(MOVING);
		}
		else {
			IS_RUNNING = false;
			continue;
		}

		MOVING = ' ';

		mx.lock();
		cg.getPeople().DrawPLayer();
		cg.updatePosVehicle();
		cg.updatePosAnimal();
		cg.drawGame();
		mx.unlock();

		if (cg.getPeople().getY() == 2) {
			cg.getPeople().LevelUp();
			if (cg.getPeople().isFinish()) {
				if (cg.askRestart(mx)) {
					cg.getPeople().getLevel() = 1;
					if (templv != cg.getPeople().getLevel())
					{
						sCar = eCar;
						sTruck = eTruck;
					}
					cg.resetData();
				}
				else
					break;
			}
			MOVING = ' ';
			cg.resetGame();
			cg.drawBackground();
		}
		Sleep(100);
	}
}


int main() {
	//choiceInMenu = 0;
	FixConsoleWindow();
	ShowConsoleCursor(0);
	//StartMenu();
	IngameMenu();
	int temp;
	FixConsoleWindow();
	ShowConsoleCursor(0);
	thread t1;
	IS_RUNNING = true;
	cg.getPeople().setAlive();
	temp = ' ';
	cg.startGame(t1);
	bool exitFromSaveGame = false;
	while (1) {
		if (_kbhit()) {
			temp = _getch();
			MOVING = temp;
		}
		if (!cg.getPeople().isDead()) {
			if (temp == 27) {
				cg.exitGame(&t1, IS_RUNNING);
				break;
			}
			else if (temp == 'p') {
				cg.pauseGame(t1);
			}
			else if (temp == 'r') {
				cg.resumeGame(t1);
			}
			else if (temp == 'w' || temp == 'a' || temp == 's' || temp == 'd') {
				cg.resumeGame(t1);
			}
		}
	}
	return 0;
}