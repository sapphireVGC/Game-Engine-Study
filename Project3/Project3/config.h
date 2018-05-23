#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class config
{
public:
	config();
	~config();

	void LoadConfig();
	void SplitString(const string& s);
	void Check(const string& r, const string& j);
	int getHP();
	int getATK();

	string line;
	string race;
	string job;
	int readHP;
	int readATK;
	const string dir = "config.txt";
};

