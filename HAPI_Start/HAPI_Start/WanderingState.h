#pragma once
#include "ChickenState.h"

class Chicken;

class WanderingState : public ChickenState
{
private:
	bool hasDirection = false;

public:
	ChickenState* Handle(Chicken& chicken);
	void Enter(Chicken& chicken);
	void Update(Chicken& chicken);
};