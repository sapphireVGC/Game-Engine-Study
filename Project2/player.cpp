#include "player.h"
#include <string>

player::player(){

}

player::~player(){

}

void player::DisplayStats() {
	cout << "\t-------Player Stats--------";
	cout << "\n\tHP: " << HP << " / " << maxHP;
	cout << "\n\tATK: " << ATK;
	cout << "\n\tPosition: (" << POS[0] << ", " << POS[1] << ")";
	cout << "\n\t----------------------------" << endl;
}

int player::GetHP() {
	return HP;
}

int player::GetATK() {
	return ATK;
}

void player::SetDATA(int x) {
	HP = x;
}

int player::GetPOSx() {
	return POS[0];
}

int player::GetPOSy() {
	return POS[1];
}

void player::SetPOS(int x, int y) {
	POS[0] = x;
	POS[1] = y;
}

void player::SpawnPlayer() {
	int ranPosX = 0;
	int ranPosY = 0;
	ranPosX = rand() % 30;
	ranPosY = rand() % 30;
	SetPOS(ranPosX, ranPosY);
	DisplayStats();
}

