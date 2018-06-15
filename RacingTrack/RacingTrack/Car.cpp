#include "Car.h"

using namespace std;

Car::Car() {

}

Car::~Car() {

}

void Car::SetDATA(const int i) {
	fuel = i;
}

void Car::SetDATA(const string& s, const int i, const char c) {
	name = s;
	fuel = i;
	symbol = c;
}

void Car::SetPos(const int i) {
	pos = i;
}

string Car::GetNAME() {
	return name;
}

int Car::GetFUEL() {
	return fuel;
}

int Car::GetPos() {
	return pos;
}

char Car::GetSYMBOL() {
	return symbol;
}