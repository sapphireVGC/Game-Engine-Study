#include "config.h"

config::config()
{
}


config::~config()
{
}

void config::LoadConfig() {
	ifstream myFile(dir);
	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			SplitString(line);
		}
		myFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void config::SplitString(const string& s) {
	istringstream ss(s);
	string token;
	string detail[4];
	int i = 0;
	while (getline(ss, token, ',')) {
		detail[i] = token;
		i++;
	}
	if (detail[0] == race && detail[1] == job) {
		readHP = stoi(detail[2]);
		readATK = stoi(detail[3]);
	}
}

void config::Check(const string& r, const string& j) {
	race = r;
	job = j;
	LoadConfig();
}

int config::getHP() {
	return readHP;
}

int config::getATK() {
	return readATK;
}
