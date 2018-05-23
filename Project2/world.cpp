#include "world.h"
#include <string>

world::world() {

}

world::~world() {

}

void world::SpawnMonster(int i) {
	int ranType = 0;
	ranType = rand() % 1;
	if (ranType == 0) {
		orcs[i]->SetType();
		cf->Check("Orc", orcs[i]->TYPE);
		orcs[i]->SetHP(cf->getHP());
		orcs[i]->SetATK(cf->getATK());
		orcs[i]->SetPOS(orcSpwnPntX, SpwnPntY);
		arrayxy[orcSpwnPntX][SpwnPntY] = i;
	}
	else {
		zombies[i]->SetType();
		cf->Check("Zombie", zombies[i]->TYPE);
		zombies[i]->SetHP(cf->getHP());
		zombies[i]->SetATK(cf->getATK());
		zombies[i]->SetPOS(zombieSpwnPntX, SpwnPntY);
		arrayxy[zombieSpwnPntX][SpwnPntY] = i;
	}
}

void world::PrintGrid() {
	cout << '\n';
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			if (i == p->GetPOSx() && j == p->GetPOSy()) {
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
	SpawnMonster(0);
	p->SpawnPlayer();
	PrintGrid();
	Instruction();
}

void world::Attack() {
	/*if (arrayxy[p.GetPOSx()][p.GetPOSy()] > 0) {
		int i;
		i = mons[arrayxy[p.GetPOSx()][p.GetPOSy()]].GetHP();
		i -= p.GetATK();
		mons[arrayxy[p.GetPOSx()][p.GetPOSy()]].SetHP(i);
		if (i <= 0) {
			i = 0;
			cout << "\n\tOrc" << arrayxy[p.GetPOSx()][p.GetPOSy()] << " is dead !!!" << endl;
			arrayxy[p.GetPOSx()][p.GetPOSy()] = 0;
		}
		else {
			int j;
			j = p.GetHP();
			j -= 2;
			p.SetDATA(j);
			p.DisplayStats();
			mons[arrayxy[p.GetPOSx()][p.GetPOSy()]].DisplayStats();
			if (j == 0) {
				cout << "\n\n\tPlayer is dead !!!" << endl << endl;
				Start();
			}
		}
	}*/
}

void world::GetInput() {
	int i;
	int j;
	char c;
	cin >> c;
	i = p->GetPOSx();
	j = p->GetPOSy();
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
	p->SetPOS(i, j);
	PrintGrid();
	Instruction();
}
