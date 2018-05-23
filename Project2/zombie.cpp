#include "zombie.h"
#include <string>

zombie::zombie(){
	//cout << "\n\tBuilding a Zombie";
}


zombie::~zombie(){
	//cout << "\n\tDestroying a Zombie";
}

void zombie::SetType() {
	int ranType;
	const string race = " zombie";
	ranType = rand() % 2;
	if (ranType == 0)
		TYPE = "Rotten";
	else
		TYPE = "Neo";
	NAME = TYPE + race;
}

string zombie::GetType() {
	return TYPE;
}
