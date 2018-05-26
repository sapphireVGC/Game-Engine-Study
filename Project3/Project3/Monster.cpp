#include "Monster.h"

using namespace std;

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Display() {
	cout << "\n\n\t-------Monster Stats--------";
	cout << "\n\tName: " << NAME;
	cout << "\n\tHp: " << HP;
	cout << "\n\tAtk: " << ATK;
	cout << "\n\tPosition: (" << POS[0] << ", " << POS[1] << ")";
	cout << "\n\t----------------------------" << endl;
}

void Monster::setHP(const int i) {
	HP = i;
}

void Monster::setATK(const int i) {
	ATK = i;
}

void Monster::setPOS(const int i, const int j) {
	POS[0] = i;
	POS[1] = j;
}

void Monster::setNAME(const string& i) {
	NAME = i;
}

int Monster::getHP() {
	return HP;
}

int Monster::getATK() {
	return ATK;
}

int Monster::getPOSX() {
	return POS[0];
}

int Monster::getPOSY() {
	return POS[1];
}

string Monster::getNAME() {
	return NAME;
}

