#pragma once
#include <iostream>

class Player final
{
public:
	Player();
	~Player();

	Player(const Player& other) = default;
	Player& operator= (Player& other) = default;

	void Display();
	void SetHP(const int x);
	void SetPOS(const int x, const int y);
	void UpdateEXP();
	int GetHP();
	int GetATK();
	int GetPOSX();
	int GetPOSY();
	
	int HP;
	int POS[2];
	int LV = 1;
	int EXP = 0;
	int maxHP = 1000;
	int ATK = 50;
};

