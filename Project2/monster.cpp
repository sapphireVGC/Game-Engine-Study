#include "monster.h"
#include <string>

monster::monster() {
	//cout << "\n\tCreating a monster...";
}

monster::~monster() {
	//cout << "\n\tDestroying a monster...";
}

void monster::attack() {
	//cout << "\n\tMonster is attacking!";
}

void monster::DisplayStats() {
	cout << "\n\n\t-------Monster Stats--------";
	cout << "\n\tName: " << NAME;
	cout << "\n\tHP: " << HP;
	cout << "\n\tPosition: (" << POS[0] << ", " << POS[1] << ")";
	cout << "\n\t----------------------------";
}

int monster::GetHP() {
	return HP;
}

void monster::SetHP(int x) {
	HP = x;
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

string monster::GetMonsterType() {
	return TYPE;
}

void monster::SetMonsterType(string x) {
	TYPE = x;
}

string monster::GetMonsterName() {
	return NAME;
}

void monster::SetMonsterName(string x) {
	NAME = x;
}