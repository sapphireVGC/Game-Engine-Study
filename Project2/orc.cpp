#include "orc.h"
#include <string>

orc::orc(){
	//cout << "\n\tBuilding an Orc";
}


orc::~orc(){
	//cout << "\n\tDestroying an Orc";
}

void orc::SetType() {
	int ranType;
	const string race = "Orc ";
	ranType = rand() % 2;
	if (ranType == 0)
		TYPE = string("Warrior");
	else
		TYPE = string("Mage");
	NAME = race + TYPE;
}

string orc::GetType() {
	return TYPE;
}
