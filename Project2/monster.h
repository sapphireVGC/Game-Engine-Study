#pragma once
#include <iostream>
#include <string>

using namespace std;

class monster {
public:
	monster();
	virtual ~monster();

	void DisplayStats();
	int GetHP();
	void SetHP(int x);
	int GetATK();
	void SetATK(int x);
	int GetPOSx();
	int GetPOSy();
	void SetPOS(int x, int y);
	string GetMonsterName();
	void SetMonsterName(string x);

	int HP;
	int ATK;
	int POS[2];
	string NAME;
	string TYPE;
};
