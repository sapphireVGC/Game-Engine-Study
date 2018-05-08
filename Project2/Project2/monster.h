#pragma once
#include <iostream>
#include <string>

using namespace std;

class monster {
public:
	monster();
	~monster();

	void attack();
	void DisplayStats();
	int GetHP();
	void SetHP(int x);
	int GetPOSx();
	int GetPOSy();
	void SetPOS(int x, int y);
	string GetMonsterType();
	void SetMonsterType(string x);
	string GetMonsterName();
	void SetMonsterName(string x);

	int ATK;
	int HP;
	int POS[2];
	string TYPE;
	string NAME;
};