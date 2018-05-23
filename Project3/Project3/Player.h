#pragma once
#include <iostream>

using namespace std;

class Player final
{
public:
	Player();
	~Player();

	void Display();
	void SetHP(const int& x);
	void SetPOS(const int& x, const int& y);
	int GetHP();
	int GetATK();
	int GetPOSX();
	int GetPOSY();
	
	int HP;
	int POS[2];
	const int maxHP = 1000;
	const int ATK = 50;
};

