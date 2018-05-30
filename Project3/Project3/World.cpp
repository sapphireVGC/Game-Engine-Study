#include "World.h"

using namespace std;

World::World()
{
	for (int i = 0; i < gridSize; i++) {
		o[i] = new Orc();
		zb[i] = new Zombie();
		for (int j = 0; j < gridSize; j++) {
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
	ran = rand() % cf->job_cnt.size();
	int ranPOS[2];
	ranPOS[0] = rand() % gridSize;
	ranPOS[1] = rand() % gridSize;
	if (ran == 0 && orcCnt < gridSize) {
		cf->Check(0);
		o[orcCnt]->setNAME(cf->getNAME());
		o[orcCnt]->setHP(cf->getHP());
		o[orcCnt]->setATK(cf->getATK());
		o[orcCnt]->setPOS(ranPOS[0], ranPOS[1]);
		orcCnt++;
	}
	else if (ran == 1 && zombieCnt < gridSize) {
		cf->Check(1);
		zb[orcCnt]->setNAME(cf->getNAME());
		zb[orcCnt]->setHP(cf->getHP());
		zb[orcCnt]->setATK(cf->getATK());
		zb[orcCnt]->setPOS(ranPOS[0], ranPOS[1]);
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
			int atk = o[i]->getATK();
			hp += 5;
			atk += 5;
			o[i]->setHP(hp);
			o[i]->setATK(atk);
			ran = rand() % 6;
			x = o[i]->getPOSX();
			y = o[i]->getPOSY();
			if (ran == 0) {
				if (x != 0)
					x--;
			}
			else if (ran == 1) {
				if (x != gridSize - 1)
					x++;
			}
			else if (ran == 2) {
				if (y != 0)
					y--;
			}
			else if (ran == 3) {
				if (y != gridSize - 1)
					y++;
			}
			o[i]->setPOS(x, y);
		}
	}
	for (int i = 0; i < zombieCnt; i++) {
		if (zb[i]->getPOSX() != p->GetPOSX() || zb[i]->getPOSY() != p->GetPOSY()) {
			int hp = zb[i]->getHP();
			hp += 20;
			zb[i]->setHP(hp);
			ran = rand() % 6;
			x = zb[i]->getPOSX();
			y = zb[i]->getPOSY();
			if (ran == 0) {
				if (x != 0)
					x--;
			}
			else if (ran == 1) {
				if (x != gridSize - 1)
					x++;
			}
			else if (ran == 2) {
				if (y != 0)
					y--;
			}
			else if (ran == 3) {
				if (y != gridSize - 1)
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
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
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
	if (p->GetLV() > 1)
		cout << "\t\tG = Ultimate Attack" << endl;
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
			o[k]->setHP(mHp);
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
		}
	}
	for (int k = 0; k < zombieCnt; k++) {
		if (i == zb[k]->getPOSX() && j == zb[k]->getPOSY()) {
			mHp = zb[k]->getHP();
			mHp -= p->GetATK();
			zb[k]->setHP(mHp);
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
		}
	}
	p->SetHP(pHp);
}

void World::Ultimate() {
	const int dmg = (p->GetLV() - 1) * 500;
	int mHp;
	p->SetLV();
	for (int i = 0; i < orcCnt; i++) {
		mHp = o[i]->getHP();
		mHp -= dmg;
		o[i]->setHP(mHp);
		if (mHp <= 0) {
			cout << "\n\t" << o[i]->getNAME() << "is Dead !!" << endl;
			for (int l = i + 1; l < orcCnt; l++) {
				o[l - 1] = o[l];
			}
			delete o[orcCnt];
			o[orcCnt] = NULL;
			o[orcCnt] = new Orc();
			orcCnt--;
			p->UpdateEXP();
		}
	}
	for (int i = 0; i < zombieCnt; i++) {
		mHp = zb[i]->getHP();
		mHp -= dmg;
		zb[i]->setHP(mHp);
		if (mHp <= 0) {
			cout << "\n\t" << zb[i]->getNAME() << "is Dead !!" << endl;
			for (int l = i + 1; l < zombieCnt; l++) {
				zb[l - 1] = zb[l];
			}
			delete zb[zombieCnt];
			zb[zombieCnt] = NULL;
			zb[zombieCnt] = new Zombie();
			zombieCnt--;
			p->UpdateEXP();
		}
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
		if (i != gridSize - 1)
			i++;
	if (c == 'a')
		if (j != 0)
			j--;
	if (c == 'd')
		if (j != gridSize - 1)
			j++;
	if (c == 'f')
		Attack(i, j);
	if (c == 'g')
		Ultimate();
	if (p->GetHP() <= 0) {
		delete p;
		p = NULL;
		cout << "\n\tPlayer is Dead !!" << endl << endl;
		SpawnPlayer();
		i = p->GetPOSX();
		j = p->GetPOSY();
	}
	p->SetPOS(i, j);
	Update();
	SpawnMonster();
	UpdateArray();
	Draw();
	Status(i, j);
	Instruction();
}
