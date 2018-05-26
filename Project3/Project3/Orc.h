#pragma once
#include "Monster.h"

class Orc :
	public Monster
{
public:
	Orc();
	~Orc();

	Orc(const Orc& other) = default;
	Orc& operator= (Orc& other) = default;
};

