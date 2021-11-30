#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<random>
#include<chrono>
using namespace std;
#include"CGAME.h"
#include"CONSOLE.h"

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
	//cg.drawBackground();
	auto startTruck = sc.now();
	auto startCar = sc.now();
	while (IS_RUNNING) {
		// functions to simulate traffic lights
		auto endTruck = sc.now();
		auto endCar = sc.now();
		auto time_spanTruck = static_cast<chrono::duration<double>>(endTruck - startTruck);
		auto time_spanCar = static_cast<chrono::duration<double>>(endCar - startCar);

		if (templv < cg.getPeople().getLevel())
		{
			startCar = endCar;
			startTruck = endTruck;
		}
		else
		{
			if (int(time_spanTruck.count()) < 5)
				cg.getTruckLight().setLight(true);
			else if (int(time_spanTruck.count()) > 5 && int(time_spanTruck.count()) < 10)
				cg.getTruckLight().setLight(false);
			else if (int(time_spanTruck.count()) > 10)
				startTruck = endTruck;
			if (int(time_spanCar.count()) < 10)
				cg.getCarLight().setLight(true);
			else if (int(time_spanCar.count()) > 5 && int(time_spanCar.count()) < 15)
				cg.getCarLight().setLight(false);
			else if (int(time_spanCar.count()) > 15)
				startCar = endCar;
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
		//if (hitSth) {
		//	cg.getPeople().dieEffect();
		//	cg.getPeople().setDead();
		//	//if (sound) cg.ambulanceVoice();
		//	cg.ambulanceEffect(mx);
		//	break;
		//}
		cg.updateLevel();

		// If player is still alive
		if (!cg.getPeople().isDead())
		{
			if (MOVING != ' ')
				// Update player's position from main
				cg.updatePosPeople(MOVING);
		}
		else {
			IS_RUNNING = false;
			continue;
		}

		// Waiting for next move from main
		MOVING = ' ';

		mx.lock();
		cg.getPeople().DrawPLayer();
		cg.updatePosVehicle();
		cg.updatePosAnimal();
		cg.drawGame();
		mx.unlock();
		
		if (cg.getPeople().getY() == 1) {
			cg.getPeople().LevelUp();
			if (cg.getPeople().isFinish()) {
				//cg.congrats();
				//if (sound) cg.congratsVoice();
				if (cg.askRestart(mx)) {
					cg.getPeople().getLevel() = 1;
					if (templv != cg.getPeople().getLevel())
					{
						startCar = endCar;
						startTruck = endTruck;
					}
					cg.resetData();
				}
				else
					break;
			}
			cg.resetGame();
			cg.drawBackground();
		}
		Sleep(100);
	}
}


int main()
{
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