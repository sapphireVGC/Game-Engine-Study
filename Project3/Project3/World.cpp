#include "World.h"

World::World()
{
	for (int i = 0; i < 30; i++) {
		o[i] = new Orc();
		zb[i] = new Zombie();
		for (int j = 0; j < 30; j++) {
			posArray[i][j] = 0;
		}
	}
}

World::~World()
{
}

void World::SpawnPlayer() {
	const int i = p->maxHP;
	p->SetHP(i);
	p->SetPOS(15, 15);
	p->Display();
}

void World::SpawnMonster(const int& i) {
	for (int j = 0; j < i; j++) {
		int ran = 0;
		ran = rand() % 2;
		if (ran == 0 && orcCnt < 30) {
			ran = rand() % 2;
			if (ran == 0) {
				cf->Check("Orc", "Warrior");
				o[orcCnt]->setNAME(0);
			}
			else {
				cf->Check("Orc", "Mage");
				o[orcCnt]->setNAME(1);
			}
			o[orcCnt]->setHP(cf->getHP());
			o[orcCnt]->setATK(cf->getATK());
			o[orcCnt]->setPOS(15, 10);
			orcCnt++;
		}
		else if (zombieCnt < 30) {
			ran = rand() % 2;
			if (ran == 0) {
				cf->Check("Zombie", "Rotten");
				zb[zombieCnt]->setNAME(2);
			}
			else {
				cf->Check("Zombie", "Neo");
				zb[zombieCnt]->setNAME(3);
			}
			zb[zombieCnt]->setHP(cf->getHP());
			zb[zombieCnt]->setATK(cf->getATK());
			zb[zombieCnt]->setPOS(15, 20);
			zombieCnt++;
		}
	}
}

void World::UpdateArray() {
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			posArray[i][j] = 0;
			for (int k = 0; k < orcCnt; k++) {
				if (i == o[k]->getPOSX() && j == o[k]->getPOSY())
					posArray[i][j] = 1;
			}
			for (int k = 0; k < zombieCnt; k++) {
				if (i == zb[k]->getPOSX() && j == zb[k]->getPOSY())
					posArray[i][j] = 1;
			}
			if (i == p->GetPOSX() && j == p->GetPOSY())
				posArray[i][j] = 2;
		}
	}
}

void World::Draw() {
	cout << '\n';
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (posArray[i][j] == 0)
				cout << "--  ";
			else if (posArray[i][j] == 1)
				cout << "XX  ";
			else
				cout << "00  ";
		}
		cout << '\n';
	}
	cout << endl;
}

void World::Instruction() {
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

void World::Status(const int& i, const int& j) {
	p->Display();
	for (int k = 0; k < orcCnt; k++) {
		if (i == o[k]->getPOSX() && j == o[k]->getPOSY())
			o[k]->Display();
	}
	for (int k = 0; k < zombieCnt; k++) {
		if (i == zb[k]->getPOSX() && j == zb[k]->getPOSY())
			zb[k]->Display();
	}
}

void World::GetInput() {
	int i;
	int j;
	char c;
	string s;
	cin >> s;
	c = s[0];
	i = p->GetPOSX();
	j = p->GetPOSY();
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
	//if (c == 'f')
		//Attack();
	p->SetPOS(i, j);
	UpdateArray();
	Draw();
	Status(i, j);
	Instruction();
}
