#include "Config.h"

using namespace std;

Config::Config() {

}

Config::~Config() {

}

void Config::LoadConfig(const int i) {
	string dir;
	if (i == 0)
		dir = carCf;
	else if (i == 1)
		dir = map1Cf;
	else if (i == 2)
		dir = map2Cf;
	ifstream myFile(dir);
	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			if (i == 0)
				SplitCar(line);
			else
				SplitString(line);
		}
		myFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void Config::SplitString(const std::string& s) {
	istringstream ss(s);
	string temp;
	while (getline(ss, temp, ' ')) {
		mapVec.push_back(stoi(temp));
	}
}

void Config::SplitCar(const std::string& s) {
	istringstream ss(s);
	string temp;
	int i = 0;
	bool found = false;
	while (getline(ss, temp, ':')) {
		if (temp == target) {
			found = true;
			carTemp[i] = temp; 
		}
		if (found) {
			carTemp[i] = temp;
		} 
		i++;
	}
}

void Config::SetTARGET(const std::string& s) {
	target = s;
}

int Config::ReadMap(const int i) {
	return mapVec.at(i);
}

string Config::GetTEMP(const int i) {
	return carTemp[i];
}
