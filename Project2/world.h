#pragma once
#include "monster.h"
#include "player.h"

class world {
public:
	world();
	virtual ~world();

	void SpawnMonster(int i);
	void PrintGrid();
	void Instruction();
	void Start();
	void Attack();
	void GetInput();

	monster orcs[100];
	player p;
	int arrayxy[30][30];
};

