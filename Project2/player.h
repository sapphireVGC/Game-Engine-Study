#pragma once
#include <iostream>
#include <string>

using namespace std;

class player
{
public:
	player();
	~player();

	void DisplayStats();
	int GetHP();
	void SetHP(int x);

	int HP;
	int maxHP = 0;
};

