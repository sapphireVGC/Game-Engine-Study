#include "Player.h"

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::Display() {
	cout << "\t-------Player Stats--------";
	cout << "\n\tLV: " << LV;
	cout << "\n\tEXP: " << EXP << " / 5";
	cout << "\n\tHP: " << HP << " / " << maxHP;
	cout << "\n\tATK: " << ATK;
	cout << "\n\tPosition: (" << POS[0] << ", " << POS[1] << ")";
	cout << "\n\t---------------------------" << endl;
}

int Player::GetHP() {
	return HP;
}

int Player::GetATK() {
	return ATK;
}

void Player::SetHP(const int x) {
	HP = x;
}

int Player::GetPOSX() {
	return POS[0];
}

int Player::GetPOSY() {
	return POS[1];
}

void Player::SetPOS(const int x, const int y) {
	POS[0] = x;
	POS[1] = y;
}

void Player::SetLV() {
	LV = 1;
	maxHP = 1000;
	if (HP > maxHP)
		HP = maxHP;
	ATK = 50;
}

int Player::GetLV() {
	return LV;
}

void Player::UpdateEXP() {
	EXP++;
	if (EXP == 5) {
		LV++;
		maxHP += 250;
		HP = maxHP;
		ATK += 25;
		EXP = 0;
	}
}