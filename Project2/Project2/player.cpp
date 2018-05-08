#include "player.h"
#include <string>

player::player(){

}

player::~player(){

}

void player::DisplayStats() {
	cout << "\t-------Player Stats--------";
	cout << "\n\tHP: " << HP << " / " << maxHP;

	if (HP == 0)
		cout << "\n\tPlayer is dead!!!";

	cout << "\n\t----------------------------";
}

int player::GetHP() {
	return HP;
}

void player::SetHP(int x) {
	if (maxHP == 0) 
		maxHP = x;

	HP = x;
}
