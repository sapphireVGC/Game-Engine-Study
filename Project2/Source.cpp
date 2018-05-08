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

int arrayxy[30][30];

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

	arrayxy[ranPosX][ranPosY] = i;
}

void PrintGrid() {
	cout << "\n\nGrid\n" << endl;

	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (arrayxy[i][j] == 0)
				cout << "--  ";
			else if (arrayxy[i][j] < 10)
				cout << "0" << arrayxy[i][j] << "  ";
			else
				cout << arrayxy[i][j] << "  ";
		}
		cout << '\n';
	}

	cout << endl;
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
			
			arrayxy[orcs[i].GetPOSx()][orcs[i].GetPOSy()] = 0;

			SpawnMonster(i);
		}
	}

	PrintGrid();
}

int main() {
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			arrayxy[i][j] = 0;
		}
	}

	for (int i = 0; i < 100; i++) {
		SpawnMonster(i);
	}

	PrintGrid();

	std::chrono::seconds interval(10);
	
	while (true) {
		std::this_thread::sleep_for(interval);
		std::cout << "\n\n\ttick!" << std::flush;
		Update();
	}

	getchar();

	return 0;
}