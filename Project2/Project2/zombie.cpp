#include "zombie.h"
#include <string>

zombie::zombie(){
	//cout << "\n\tBuilding a Zombie";
}


zombie::~zombie(){
	//cout << "\n\tDestroying a Zombie";
}

void zombie::bite() {
	cout << "\n\n\tZombie is bitting Player!\n";
}
