#pragma once

#include <algorithm>
#include<time.h>
#include <string>
#include <iostream>
#include<vector>
#include<mutex>
#include <conio.h>
#include<fstream>
#include"CPEOPLE.h"
#include"CTRUCK.h"
#include"CCAR.h"
#include"CDINAUSOR.h"
#include"CBIRD.h"
#include"CTRAFFICLIGHT.h"
#include"CAMBULANCE.h"
#include"CONSOLE.h"
#include"Header.h"
using namespace std;
class CGAME {
private:
	CTRUCK* axt;
	CCAR* axh;
	CVEHICLE** veh;
	CDINAUSOR* akl;
	CBIRD* ac;
	CANIMAL **ani;
	CPEOPLE cn;
	CTRAFFICLIGHT dxh;
	CTRAFFICLIGHT dxt;
	vector<int> xh;
	vector<int> xt;
	vector<int> kl;
	vector<int> c;
public:
	CGAME();
	void updateObstacle();
	//Chuẩn bị dữ liệu cho tất cả các đối tượng 
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void drawBackground();//Vẽ background
	~CGAME(); // Hủy tài nguyên đã cấp phát
	CPEOPLE& getPeople();//Lấy thông tin người
	CTRUCK* getTruck();
	CCAR* getCar();
	CBIRD* getBird();
	CDINAUSOR* getDinausor();
	CANIMAL** getAnimal();
	CVEHICLE** getVehicle();
	CTRAFFICLIGHT& getCarLight();
	CTRAFFICLIGHT& getTruckLight();
	
	void updateLevel();
	//void clearGame();
	bool askRestart(mutex& mx);
	void resetGame();
	void resetData();
	// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread*,bool&); // Thực hiện thoát Thread 
	void startGame(thread&); // Thực hiện bắt đầu vào trò chơi
	void loadGame(mutex&,bool = false); // Thực hiện tải lại trò chơi đã lưu
	//void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi
	bool saveGame(mutex&, bool = false);
	void pauseGame(thread&); // Tạm dừng Thread
	void resumeGame(thread&); //Quay lai Thread
	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void clearMessage(int x, int y, int length);
	bool checkFileExist(const string& fileName);
	void writeFile(ostream& stream, int x);
	int readFile(ifstream& stream);
	void ambulanceEffect(mutex&);
	void ambulanceSound(mutex&);
};

