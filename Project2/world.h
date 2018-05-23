#pragma once
#include "monster.h"
#include "orc.h"
#include "zombie.h"
#include "player.h"
#include "config.h"

class world final{
public:
	world();
	~world();

	void SpawnMonster(int i);
	void PrintGrid();
	void Instruction();
	void Start();
	void Attack();
	void GetInput();

	player *p = new player();
	config *cf = new config();
	orc **orcs = new orc*[100];
	zombie **zombies = new zombie*[100];
	int arrayxy[30][30];
	const int orcSpwnPntX = 10;
	const int zombieSpwnPntX = 20;
	const int SpwnPntY = 15;
};

