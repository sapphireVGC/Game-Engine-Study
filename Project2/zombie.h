#pragma once
#include "monster.h"

class zombie : public monster {
public:
	zombie();
	virtual ~zombie();

	void SetType();
	string GetType();
};

