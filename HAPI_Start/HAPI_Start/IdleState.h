#pragma once
#include "ChickenState.h"

class Chicken;

class IdleState : public ChickenState
{
public:
	ChickenState* Handle();
	void Update(Chicken& chicken);
};

