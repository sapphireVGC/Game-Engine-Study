#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class config final {
public:
	config();
	~config();

	void LoadConfig(string r, string j);
	void SplitString(string s, string r, string j);
	void Check(string r, string j);
	int getHP();
	int getATK();

	string line;
	string race;
	string job;
	int readHP;
	int readATK;
	const string dir = "config.txt";
};

