#pragma once
#include "monster.h"
class zombie :
	public monster
{
public:
	zombie();
	~zombie();

	void bite();
};

