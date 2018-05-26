#pragma once
#include "Monster.h"

class Zombie :
	public Monster
{
public:
	Zombie();
	~Zombie();

	Zombie(const Zombie& other) = default;
	Zombie& operator= (Zombie& other) = default;
};

