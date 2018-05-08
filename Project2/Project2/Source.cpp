#include "monster.h"
#include "orc.h"
#include "zombie.h"
#include "player.h"
#include "grid.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

orc orcs[100];

void SpawnMonster(int i) {
	int ranHP = 0;
	ranHP = rand() % 10 + 1;

	int ranPosX = 0;
	int ranPosY = 0;

	bool checkPos;

	do {
		ranPosX = rand() % 30;
		ranPosY = rand() % 30;
		checkPos = false;
			
		for (int ii = 0; ii < i; ii++) {
			if (ranPosX == orcs[i].GetPOSx()) {
				if (ranPosY == orcs[i].GetPOSy()) {
					checkPos = true;

					break;
				}
			}
		}
	} while (checkPos && i != 0);

	orcs[i].SetMonsterName("Orc" + std::to_string(i));
	orcs[i].SetHP(ranHP);
	orcs[i].SetPOS(ranPosX, ranPosY);
	orcs[i].DisplayStats();
}

void Update() {
	for (int i = 0; i < 100; i++) {
		int hp = orcs[i].GetHP();
		hp--;
		orcs[i].SetHP(hp);
		
		cout << "\n\n\tOrc" << i << "'s HP is " << hp;

		if (hp == 0) {
			cout << "\n\n\tOrc" << i << " is dead !!!";
			cout << "\n\tSpawning...";

			SpawnMonster(i);
		}
	}
}

int main() {
	for (int i = 0; i < 100; i++) {
		SpawnMonster(i);
	}
	
	std::chrono::seconds interval(10);
	
	while (true) {
		std::this_thread::sleep_for(interval);
		std::cout << "\n\n\ttick!" << std::flush;
		Update();
	}

	getchar();

	return 0;
}