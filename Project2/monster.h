#pragma once
#include <iostream>
#include <string>

using namespace std;

class monster final {
public:
	monster();
	~monster();

	void DisplayStats();
	int GetHP();
	void SetHP(int x);
	int GetPOSx();
	int GetPOSy();
	void SetPOS(int x, int y);
	string GetMonsterName();
	void SetMonsterName(string x);
	void SpawnMonster(int i);

	int HP;
	int POS[2];
	string NAME;
};
