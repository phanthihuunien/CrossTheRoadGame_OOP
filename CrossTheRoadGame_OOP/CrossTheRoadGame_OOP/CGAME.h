#pragma once
#include<mutex>
#include <conio.h>
#include<fstream>
#include"CPEOPLE.h"
#include"CTRUCK.h"
#include"CCAR.h"
#include"CDINAUSOR.h"
#include"CBIRD.h"
#include"CTRAFFICLIGHT.h"
#include"CONSOLE.h"
#include"Header.h"
class CGAME {
private:
    int carSize;
	int truckSize;
	int dinausorSize;
	int birdSize;
	CTRUCK* axt;
	CCAR* axh;
	CDINAUSOR* akl;
	CBIRD* ac;
	CPEOPLE cn;
	CTRAFFICLIGHT dxh;
	CTRAFFICLIGHT dxt;
public:
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng 
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void drawBackground();//Vẽ background
	~CGAME(); // Hủy tài nguyên đã cấp phát
	CPEOPLE getPeople();//Lấy thông tin người
	CTRUCK* getTruck();
	CCAR* getCar();
	CBIRD* getBird();
	CDINAUSOR* getDinausor();
	void clearGame();
	void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread 
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(mutex&,bool); // Thực hiện tải lại trò chơi đã lưu
	//void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi
	bool saveGame(mutex&, bool = false);
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void clearMessage(int x, int y, int length);
	bool checkFileExist(const string& fileName);
	void writeFile(std::ostream& stream, int x);
	int readFile(ifstream& stream);
};

