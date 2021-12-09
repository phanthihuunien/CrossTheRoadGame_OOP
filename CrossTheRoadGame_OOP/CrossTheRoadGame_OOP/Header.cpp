#include"Header.h"
#include"CONSOLE.h"
void EraseMenu()
{
	for (int i = 0; i < 5; i++)
	{
		gotoXY(95, 20 + i);
		for (int j = 0; j < 40; j++)
			cout << ' ';
	}
}
int StartMenu() {
	system("color 07");
	printTitle();
	int cursor = 0;
	string Menu[3] = { "1. NEW GAME", "2. LOAD GAME", "3. EXIT" };
	string Member[4] = { "1. NGUYEN TUAN DAT", "2. DAO TRONG NAM", "3. BUI DUY BAO", "4. PHAN THI HUU NIEN" };
	SET_COLOR(8);
	gotoXY(93, 23);
	cout << "Team member: ";
	for (int i = 0; i < 4; i++) {
			gotoXY(95, 25 + i);
			cout << Member[i];
	}
	
	while (true) {
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		for (int i = 0; i < 3; i++) {
			if (i == cursor) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				gotoXY(50, 12 + i);
				cout << Menu[i];
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoXY(50, 12 + i);
				cout << Menu[i];
			}
		}
		
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0) {
				cursor--;
				if (cursor == -1)
					cursor = 2;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) != 0)) {
				cursor++;
				if (cursor == 3)
					cursor = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0)) {
				switch (cursor) {
				case 0: {
					choiceMenuStart = 0;
					return choiceMenuStart;
					break;
				}
				case 1: {
					choiceMenuStart = 1;
					return choiceMenuStart;
					break;
				}
				case 2: {
					choiceMenuStart = 2;
					return choiceMenuStart;
					break;
				}
				
				break;
				}
			}
		}
	}
}

int IngameMenu() {
	system("color 07");
	int cursor = 0;
	string Menu[4] = { "1.RESUME GAME", "2.SAVE GAME", "3.LOAD GAME", "4.EXIT GAME" };
	while (true) {
		system("cls");
		for (int i = 0; i < 4; i++) {
			if (i == cursor) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				gotoXY(50, 12 + i);
				cout << Menu[i];
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoXY(50, 12 + i);
				cout << Menu[i];
			}
		}
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0) {
				cursor--;
				if (cursor == -1)
					cursor = 3;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) != 0)) {
				cursor++;
				if (cursor == 4)
					cursor = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0)) {
				switch (cursor) {
				case 0: {
					choiceMenuInGame = 0;
					return choiceMenuInGame;
					break;
				}
				case 1: {
					choiceMenuInGame = 1;
					return choiceMenuInGame;
					break;
				}
				case 2: {
					choiceMenuInGame = 2;
					return choiceMenuInGame;
					break;
				}
				case 3: {
					choiceMenuInGame = 3;
					return choiceMenuInGame;
					break;
				}
				default: break;
				}
			}
		}
	}
}