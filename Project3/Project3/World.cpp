#include "World.h"

using namespace std;

World::World()
{
	for (int i = 0; i < 30; i++) {
		o[i] = new Orc();
		zb[i] = new Zombie();
		for (int j = 0; j < 30; j++) {
			posArray[i][j] = 0;
		}
	}
	cf->LoadConfig(1);
}

World::~World()
{
}

void World::SpawnPlayer() {
	p = new Player();
	const int i = p->maxHP;
	p->SetHP(i);
	p->SetPOS(15, 15);
	p->Display();
}

void World::SpawnMonster() {
	int ran = 0;
	ran = rand() % 2;
	if (ran == 0 && orcCnt < 30) {
		ran = rand() % cf->job_cnt.at(0);
		cf->Check(0);
		o[orcCnt]->setNAME(cf->getNAME());
		o[orcCnt]->setHP(cf->getHP());
		o[orcCnt]->setATK(cf->getATK());
		o[orcCnt]->setPOS(15, 10);
		orcCnt++;
	}
	else if (ran == 1 && zombieCnt < 30) {
		ran = rand() % cf->job_cnt.at(1);
		cf->Check(1);
		zb[orcCnt]->setNAME(cf->getNAME());
		zb[orcCnt]->setHP(cf->getHP());
		zb[orcCnt]->setATK(cf->getATK());
		zb[orcCnt]->setPOS(15, 20);
		zombieCnt++;
	}
}

void World::Update() {
	int ran = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < orcCnt; i++) {
		if (o[i]->getPOSX() != p->GetPOSX() || o[i]->getPOSY() != p->GetPOSY()) {
			int hp = o[i]->getHP();
			hp += 5;
			o[i]->setHP(hp);
			ran = rand() % 6;
			x = o[i]->getPOSX();
			y = o[i]->getPOSY();
			if (ran == 0) {
				if (x != 0)
					x--;
			}
			else if (ran == 1) {
				if (x != 29)
					x++;
			}
			else if (ran == 2) {
				if (y != 0)
					y--;
			}
			else if (ran == 3) {
				if (y != 29)
					y++;
			}
			o[i]->setPOS(x, y);
		}
	}
	for (int i = 0; i < zombieCnt; i++) {
		if (zb[i]->getPOSX() != p->GetPOSX() || zb[i]->getPOSY() != p->GetPOSY()) {
			int hp = zb[i]->getHP();
			hp += 5;
			zb[i]->setHP(hp);
			ran = rand() % 6;
			x = zb[i]->getPOSX();
			y = zb[i]->getPOSY();
			if (ran == 0) {
				if (x != 0)
					x--;
			}
			else if (ran == 1) {
				if (x != 29)
					x++;
			}
			else if (ran == 2) {
				if (y != 0)
					y--;
			}
			else if (ran == 3) {
				if (y != 29)
					y++;
			}
			zb[i]->setPOS(x, y);
		}
	}
}

void World::UpdateArray() {
	for (int i = 0; i < gridSize; i++) //variable
	{
		for (int j = 0; j < gridSize; j++)
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
			if (i == p->GetPOSX() && j == p->GetPOSY() && posArray[i][j] == 1)
				posArray[i][j] = 3;
			else if (i == p->GetPOSX() && j == p->GetPOSY())
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
			else if (posArray[i][j] == 2)
				cout << "00  ";
			else
				cout << "++  ";
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

void World::Status(const int i, const int j) {
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

void World::Attack(const int i, const int j) {
	int pHp = p->GetHP();
	int mHp = 0;
	for (int k = 0; k < orcCnt; k++) {
		if (i == o[k]->getPOSX() && j == o[k]->getPOSY()) {
			mHp = o[k]->getHP();
			mHp -= p->GetATK();
			if (mHp <= 0) {
				cout << "\n\t" << o[k]->getNAME() << "is Dead !!" << endl;
				for (int l = k + 1; l < orcCnt; l++) {
					o[l - 1] = o[l];
				}
				delete o[orcCnt];
				o[orcCnt] = NULL;
				o[orcCnt] = new Orc();
				orcCnt--;
				p->UpdateEXP();
				if (pHp != p->GetHP())
					pHp = p->GetHP();
			}
			else {
				pHp -= o[k]->getATK();
			}
			o[k]->setHP(mHp);
		}
	}
	for (int k = 0; k < zombieCnt; k++) {
		if (i == zb[k]->getPOSX() && j == zb[k]->getPOSY()) {
			mHp = zb[k]->getHP();
			mHp -= p->GetATK();
			if (mHp <= 0) {
				cout << "\n\t" << zb[k]->getNAME() << "is Dead !!" << endl;
				for (int l = k + 1; l < zombieCnt; l++) {
					zb[l - 1] = zb[l];
				}
				delete zb[zombieCnt];
				zb[zombieCnt] = NULL;
				zb[zombieCnt] = new Zombie();
				zombieCnt--;
				p->UpdateEXP();
				if (pHp != p->GetHP())
					pHp = p->GetHP();
			}
			else {
				pHp -= zb[k]->getATK();
			}
			zb[k]->setHP(mHp);
		}
	}
	if (p <= 0) {
		delete p;
		p = NULL;
		cout << "\n\tPlayer is Dead !!" << endl;
		SpawnPlayer();
		UpdateArray();
		Draw();
		Instruction();
	}
	else {
		p->SetHP(pHp);
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
	if (c == 'f')
		Attack(i, j);
	p->SetPOS(i, j);
	Update();
	SpawnMonster();
	UpdateArray();
	Draw();
	Status(i, j);
	Instruction();
}
