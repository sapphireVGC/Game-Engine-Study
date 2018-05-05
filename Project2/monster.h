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
	int GetATK();
	void SetATK(int x);
	string GetMonsterType();
	void SetMonsterType(string x);
	string GetMonsterName();
	void SetMonsterName(string x);

	int ATK;
	string TYPE;
	string NAME;
};