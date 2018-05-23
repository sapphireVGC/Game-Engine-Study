#pragma once
#include "monster.h"

class orc : public monster {
public:
	orc();
	virtual ~orc();

	void SetType();
	string GetType();
};

