#pragma once
#include <iostream>
#include "Player.h"
#include "Orc.h"
#include "Zombie.h"
#include "config.h"

class World final
{
public:
	World();
	~World();

	World(const World& other) = default;
	World& operator= (World& other) = default;

	void SpawnPlayer();
	void SpawnMonster();
	void Update();
	void UpdateArray();
	void Draw();
	void Instruction();
	void Status(const int i, const int j);
	void Attack(const int i, const int j);
	void Ultimate();
	void GetInput();

	Player* p;
	Orc* o[30];
	Zombie* zb[30];
	config* cf = new config();

	int orcCnt = 0;
	int zombieCnt = 0;
	int posArray[30][30];
	const int gridSize = 30;
};

