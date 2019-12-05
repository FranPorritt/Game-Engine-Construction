#pragma once
#include "ChickenState.h"

class Chicken;

class IdleState : public ChickenState
{
public:
	ChickenState* Handle(Chicken& chicken);
	void Enter(Chicken& chicken);
	void Update(Chicken& chicken);
};

