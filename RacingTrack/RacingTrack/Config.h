#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>	
#include <vector>

class Config {
public:
	Config();
	~Config();

	Config(const Config& other) = default;
	Config& operator= (Config& other) = default;

	void LoadConfig(const int i);
	void SplitString(const std::string& s);
	void SplitCar(const std::string& s);
	void SetTARGET(const std::string& i);
	int ReadMap(const int i);
	std::string GetTEMP(const int i);

	std::string line;
	std::string carTemp[3];
	std::string target;
	const std::string carCf = "car.txt";
	std::vector<int> mapVec;
};

