#pragma once
#include <iostream>
#include <string>

using namespace std;

class player final {
public:
	player();
	~player();

	void DisplayStats();
	int GetHP();
	int GetATK();
	void SetDATA(int x);
	int GetPOSx();
	int GetPOSy();
	void SetPOS(int x, int y);
	void SpawnPlayer();

	int HP = 10;
	const int maxHP = 1000;
	const int ATK = 50;
	int POS[2];
};

