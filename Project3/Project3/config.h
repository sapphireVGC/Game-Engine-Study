#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class config
{
public:
	config();
	~config();

	config(const config& other) = default;
	config& operator= (config& other) = default;

	void LoadConfig(const int i);
	void Count(const std::string& s);
	void SplitString(const std::string& s);
	void Check(const int r);
	std::string getNAME();
	int getHP();
	int getATK();

	std::string line;
	std::string readNAME;
	int race;
	int job;
	int readHP;
	int readATK;
	int randCnt;
	const std::string dir = "config.txt";
	
	std::vector<std::string> race_list;
	std::vector<int> job_cnt;
};

