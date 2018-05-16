#pragma once
#include <iostream>
#include <string>

using namespace std;

class player final
{
public:
	player();
	~player();

	void DisplayStats();

	int GetHP();
	int GetATK();
	int GetLV();

	void SetDATA(int x);
	void SetDATA(int x, int y);
	void SetDATA(int x, int y, int z);

	int GetPOSx();
	int GetPOSy();
	void SetPOS(int x, int y);

	int HP = 10;
	int maxHP = 10;
	int ATK = 5;
	int LV = 1;
	int POS[2];
};

