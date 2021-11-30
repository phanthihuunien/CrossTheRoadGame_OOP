#include"CONSOLE.h"
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ShowConsoleCursor(bool showFlag=0)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void SET_COLOR(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void printTitle() {
	int startX = 25, startY = 0;
	string buffer;
	ifstream fin("title.txt");
	SET_COLOR(4);
	for (int i = 0; i < 20; ++i) {
		gotoXY(startX, startY + i);
		getline(fin, buffer);
		cout << buffer;
	}
}

void DrawBoard(int x, int y, int width, int height){

	SET_COLOR(8);
	gotoXY(x, y); cout << char(219);
	for (int i = 1; i < width; i++) cout << char(223);
	cout << char(219);
	gotoXY(x, height + y); cout << char(223);
	for (int i = 1; i < width; i++) cout << char(223);
	cout << char(223);
	for (int i = y + 1; i < height + y; i++){
		gotoXY(x, i); cout << char(219);
		gotoXY(x + width, i); cout << char(219);
	}
	SET_COLOR(15);
}