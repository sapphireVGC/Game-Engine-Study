#include "player.h"
#include <string>

player::player(){

}

player::~player(){

}

void player::DisplayStats() {
	cout << "\t-------Player Stats--------";
	cout << "\n\tLV: " << LV;
	cout << "\n\tHP: " << HP << " / " << maxHP;
	cout << "\n\tATK: " << ATK;
	cout << "\n\t----------------------------" << endl;
}

int player::GetHP() {
	return HP;
}

int player::GetATK() {
	return ATK;
}

int player::GetLV() {
	return LV;
}

void player::SetDATA(int x) {
	if (maxHP == 0) 
		maxHP = x;

	HP = x;
}

void player::SetDATA(int x, int y) {
	if (maxHP == 0)
		maxHP = x;

	HP = x;
	ATK = y;
}

void player::SetDATA(int x, int y, int z) {
	if (maxHP == 0)
		maxHP = x;

	HP = x;
	ATK = y;
	LV = z;
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

