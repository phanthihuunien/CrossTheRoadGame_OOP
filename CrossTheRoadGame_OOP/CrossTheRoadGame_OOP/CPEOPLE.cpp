#include"CPEOPLE.h"
#include"Header.h"
//  O   @ 
// <|> /U\      
// / \ / \

CPEOPLE::CPEOPLE() {
	tmpY = 22;
	tmpX = (MAXWIDTH / 2) - 1;
	mX = (MAXWIDTH / 2) - 1;
	mY = 22;
	mState = true;
	level = 1;
	score = 0;

}
void CPEOPLE::Up(int y) {
	tmpY = mY;
	tmpX = mX;
	if (mY - y >= 0) { //neu mY < y thi se thanh down 
		mY -= y;
	}
}
void CPEOPLE::Down(int y) {
	tmpY = mY;
	tmpX = mX;
	if (mY + y <= MAXHEIGHT) {
		mY += y;
	}

}
void CPEOPLE::Left(int x) {
	tmpY = mY;
	tmpX = mX;
	if (mX - x >= 3) {
		mX -= x;
	}

}
void CPEOPLE::Right(int x) {
	tmpY = mY;
	tmpX = mX;
	if (mX + x <= MAXWIDTH) {
		mX += x;
	}

}

bool CPEOPLE::isImpactV(CVEHICLE* const& vehicle) {
	if (mY != vehicle[0].mY)
		return false;
	for (int i = 0; i < level; i++) {
		if ((mX <= vehicle[i].mX + 4 && mX >= vehicle[i].mX) || (mX + 2 <= vehicle[i].mX && mX + 2 >= vehicle[i].mX)) {
			mState = false;
			return true;
		}
	}
	return false;
}
bool CPEOPLE::isImpactA(CANIMAL* const& animal) {

	if (mY != animal[0].mY)
		return false;
	for (int i = 0; i < level; i++) {
		if ((mX <= animal[i].mX + 4 && mX >= animal[i].mX) || (mX + 2 <= animal[i].mX && mX + 2 >= animal[i].mX)) {
			mState = false;
			return true;
		}
	}
	return false;
}
bool CPEOPLE::isFinish() {
	if (level == 10) return true;
	return false;
}

bool CPEOPLE::isLive() {
	return mState;
}

bool CPEOPLE::isDead() {
	return !mState;
}
void CPEOPLE::DrawPLayer() { // 3x3
	gotoXY(tmpX, tmpY-1);
	cout << "   ";
	gotoXY(tmpX, tmpY );
	cout << "   ";
	gotoXY(tmpX, tmpY + 1);
	cout << "   ";
	gotoXY(mX, mY-1);
	cout << " O ";
	gotoXY(mX, mY );
	cout << "<U>";
	gotoXY(mX, mY + 1);
	cout << "/" << " \\";
}
//  O   @ 
// <U> /U\      
// / \ / \

int& CPEOPLE::getLevel() {
	return level;
}

int CPEOPLE::getScore() {
	return score;
}
void CPEOPLE::LevelUp() {
	if (level < 10) level++;
}

void CPEOPLE::soundCar()
{
	PlaySound(L"car.wav", NULL, SND_FILENAME);
}

void CPEOPLE::soundTruck()
{
	PlaySound(L"truck.wav", NULL, SND_FILENAME);
}

int& CPEOPLE::getX() {
	return mX;
}

int& CPEOPLE::getY() {
	return mY;
}
void CPEOPLE::setAlive() {
	mState = 1;
}
void CPEOPLE::setDead()
{
	mState = 0;
}
void CPEOPLE::eraseOldPeople() {
	gotoXY(mX, mY); cout << "   ";
	gotoXY(mX, mY + 1); cout << "   ";
	gotoXY(mX, mY + 2); cout << "   ";
}