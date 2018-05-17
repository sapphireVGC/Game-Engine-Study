#include "world.h"
#include <string>

world::world() {

}

world::~world() {

}

void world::SpawnMonster(int i) {
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
			if (ranPosX == orcs[ii].GetPOSx()) {
				if (ranPosY == orcs[ii].GetPOSy()) {
					checkPos = true;

					break;
				}
			}
		}
	} while (checkPos && i != 0);
	orcs[i].SetMonsterName("Orc" + std::to_string(i));
	orcs[i].SetHP(ranHP);
	orcs[i].SetPOS(ranPosX, ranPosY);
	arrayxy[ranPosX][ranPosY] = i;
}

void world::PrintGrid() {
	cout << '\n';
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (i == p.GetPOSx() && j == p.GetPOSy()) {
				if (arrayxy[i][j] > 0)
					cout << "PM  ";
				else
					cout << "PP  ";
			}
			else {
				if (arrayxy[i][j] == 0)
					cout << "--  ";
				else if (arrayxy[i][j] > 0)
					cout << "MM  ";
			}
		}
		cout << '\n';
	}
	cout << endl;
}

void world::Instruction() {
	cout << "\t==============================" << endl;
	cout << "\tKey Guide" << endl;
	cout << "\t\tW = Move Up" << endl;
	cout << "\t\tA = Move Left" << endl;
	cout << "\t\tS = Move Down" << endl;
	cout << "\t\tD = Move Right" << endl;
	cout << "\t\tF = Attack" << endl;
	cout << "\t==============================" << endl;
	cout << "\tPlease choose the action...";
}

void world::Start() {
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
	p.SpawnPlayer();
	PrintGrid();
	Instruction();
}

void world::Attack() {
	if (arrayxy[p.GetPOSx()][p.GetPOSy()] > 0) {
		int i;
		i = orcs[arrayxy[p.GetPOSx()][p.GetPOSy()]].GetHP();
		i -= p.GetATK();
		orcs[arrayxy[p.GetPOSx()][p.GetPOSy()]].SetHP(i);
		if (i <= 0) {
			i = 0;
			cout << "\n\tOrc" << arrayxy[p.GetPOSx()][p.GetPOSy()] << " is dead !!!" << endl;
			arrayxy[p.GetPOSx()][p.GetPOSy()] = 0;
		}
		else {
			orcs[arrayxy[p.GetPOSx()][p.GetPOSy()]].DisplayStats();
			int j;
			j = p.GetHP();
			j -= 2;
			p.SetDATA(j);
			if (j == 0) {
				cout << "\n\n\tPlayer is dead !!!" << endl << endl;
				Start();
			}
		}
	}
}

void world::GetInput() {
	int i;
	int j;
	char c;
	cin >> c;
	i = p.GetPOSx();
	j = p.GetPOSy();
	if (c == 'w')
		if (i != 0)
			i--;
	if (c == 's')
		if (i != 29)
			i++;
	if (c == 'a')
		if (j != 0)
			j--;
	if (c == 'd')
		if (j != 29)
			j++;
	if (c == 'f')
		Attack();
	p.SetPOS(i, j);
	PrintGrid();
	Instruction();
}
