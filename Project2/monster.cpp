#include "monster.h"
#include <string>

monster::monster() {
	//cout << "\n\tCreating a monster...";
}

monster::~monster() {
	//cout << "\n\tDestroying a monster...";
}

void monster::DisplayStats() {
	cout << "\n\n\t-------Monster Stats--------";
	cout << "\n\tName: " << NAME;
	cout << "\n\tType: " << TYPE;
	cout << "\n\tHp: " << HP;
	cout << "\n\tAtk: " << ATK;
	cout << "\n\tPosition: (" << POS[0] << ", " << POS[1] << ")";
	cout << "\n\t----------------------------" << endl;
}

int monster::GetHP() {
	return HP;
}

void monster::SetHP(int x) {
	HP = x;
}

int monster::GetATK() {
	return ATK;
}

void monster::SetATK(int x) {
	ATK = x;
}

int monster::GetPOSx() {
	return POS[0];
}

int monster::GetPOSy() {
	return POS[1];
}

void monster::SetPOS(int x, int y) {
	POS[0] = x;
	POS[1] = y;
}

string monster::GetMonsterName() {
	return NAME;
}

void monster::SetMonsterName(string x) {
	NAME = x;
}