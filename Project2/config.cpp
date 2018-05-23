#include "config.h"
#include <sstream>

config::config() {
}


config::~config() {
}

void config::LoadConfig(string r, string j) {
	ifstream myFile(dir);
	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			SplitString(line, r, j);
		}
		myFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void config::SplitString(string s, string r, string j) {
	istringstream ss(s);
	string token;
	string detail[4];
	int i = 0;
	while (getline(ss, token, ',')) {
		cout << token << '\n';
		detail[i] = token;
		i++;
	}
	if (detail[0] == r && detail[1] == j) {
		readHP = stoi(detail[2]);
		readATK = stoi(detail[3]);
	}
}

void config::Check(string r, string j) {
	race = r;
	job = j;
	LoadConfig(r, j);
}

int config::getHP() {
	return readHP;
}

int config::getATK() {
	return readATK;
}