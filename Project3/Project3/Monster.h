#pragma once
#include <iostream>
#include <string>

using namespace std;

class Monster
{
public:
	Monster();
	virtual ~Monster();

	void Display();
	void setHP(const int& i);
	void setATK(const int& i);
	void setPOS(const int& i, const int& j);
	void setNAME(const int& i);
	int getHP();
	int getATK();
	int getPOSX();
	int getPOSY();
	string getNAME();

	int HP;
	int ATK;
	int POS[2];
	string NAME;
};

