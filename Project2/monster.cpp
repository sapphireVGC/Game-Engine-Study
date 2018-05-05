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
	cout << "\n\tType: " << TYPE;
	cout << "\n\tAttack: " << ATK;
	cout << "\n\t----------------------------";
}

int monster::GetATK() {
	return ATK;
}

void monster::SetATK(int x) {
	ATK = x;
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