#pragma once
#include "ChickenState.h"

class Chicken;

class IdleState : public ChickenState
{
public:
	ChickenState* Handle();
	void Enter();
	void Update(Chicken& chicken);
};

