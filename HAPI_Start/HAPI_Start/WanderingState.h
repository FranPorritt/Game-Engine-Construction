#pragma once
#include "ChickenState.h"

class Chicken;

class WanderingState : public ChickenState
{
private:
	bool hasDirection = false;

public:
	ChickenState* Handle();
	void Enter();
	void Update(Chicken& chicken);
};