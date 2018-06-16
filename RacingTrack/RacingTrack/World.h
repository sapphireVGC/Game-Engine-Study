#pragma once
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include "Config.h"
#include "Car.h"

class World {
public:
	World();
	~World();

	World(const World& other) = default;
	World& operator= (World& other) = default;

	void InitMap();
	void Instruction();
	void WriteMap();
	void UpdateMap();
	void SpawnCar(const std::string& s);
	void GetInput();

	Config* cf = new Config();
	Car* car[2];

	const int mapSize = 10;
	int carCnt = 0;
	int startPnt = 0;
	const int timeDelay = 1;
	const int fuelCost = 2;
	char input = 0;
};

