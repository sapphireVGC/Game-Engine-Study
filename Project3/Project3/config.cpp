#include "config.h"

using namespace std;

config::config()
{
}


config::~config()
{
}

void config::LoadConfig(const int i) {
	ifstream myFile(dir);
	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			if (i == 0)
				SplitString(line);
			else if (i == 1)
				Count(line);
		}
		myFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void config::Count(const string& s) {
	istringstream ss(s);
	string token;
	string temp[2];
	int point = 0;
	bool found = false;
	for (int i = 0; i < 2; i++)
	{
		(getline(ss, temp[i], ','));
	}
	if (race_list.empty()) {
		race_list.push_back(temp[0]);
		job_cnt.push_back(1);
	}
	else {
		for (int i = 0; i < race_list.size(); i++) {
			if (temp[0] == race_list.at(i)) {
				found = true;
				point = i;
			}
		}
		if (!found) {
			race_list.push_back(temp[0]);
			job_cnt.push_back(1);
		}
		else {
			int j = job_cnt.at(point);
			j++;
			job_cnt.at(point) = j;
		}
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
	if (detail[0] == race_list.at(race)) {
		if (randCnt == job) {
			readNAME = detail[0] + detail[1];
			readHP = stoi(detail[2]);
			readATK = stoi(detail[3]);
		}
		randCnt++;
	}
}

void config::Check(const int r) {
	race = r;
	job = rand() % job_cnt.at(race);
	randCnt = 0;
	LoadConfig(0);
}

string config::getNAME() {
	return readNAME;
}

int config::getHP() {
	return readHP;
}

int config::getATK() {
	return readATK;
}
