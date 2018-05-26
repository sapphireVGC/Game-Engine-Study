#pragma once
#include <iostream>
#include <string>

class Monster
{
public:
	Monster();
	virtual ~Monster();

	Monster(const Monster& other) = default;
	Monster& operator= (Monster& other) = default;

	void Display();
	void setHP(const int i);
	void setATK(const int i);
	void setPOS(const int i, const int j);
	void setNAME(const std::string& i);
	int getHP();
	int getATK();
	int getPOSX();
	int getPOSY();
	std::string getNAME();

	int HP;
	int ATK;
	int POS[2];
	std::string NAME;
};

