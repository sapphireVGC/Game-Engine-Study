#pragma once
#include <iostream>
#include "Player.h"
#include "Orc.h"
#include "Zombie.h"
#include "config.h"

using namespace std;

class World final
{
public:
	World();
	~World();

	void SpawnPlayer();
	void SpawnMonster(const int& i);
	void UpdateArray();
	void Draw();
	void Instruction();
	void Status(const int& i, const int& j);
	void GetInput();

	Player* p = new Player();
	Orc* o[30];
	Zombie* zb[30];
	config* cf = new config();

	int orcCnt = 0;
	int zombieCnt = 0;
	int posArray[30][30];
};

