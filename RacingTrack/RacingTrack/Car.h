#pragma once
#include <iostream>
#include <string>

class Car {
public:
	Car();
	~Car();

	Car(const Car& other) = default;
	Car& operator= (Car& other) = default;

	void SetDATA(const int i);
	void SetDATA(const std::string& s, const int i, const char c);
	void SetPos(const int i);
	void SetPastPos(const int i);
	std::string GetNAME();
	int GetFUEL();
	int GetPos();
	int GetPastPos();
	char GetSYMBOL();

	std::string name;
	int fuel;
	int pos;
	int pastPos;
	char symbol;
};

