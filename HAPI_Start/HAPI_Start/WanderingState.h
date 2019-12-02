#pragma once
#include "ChickenState.h"

class Chicken;

class WanderingState : public ChickenState
{
public:
	ChickenState* Handle();
	void Update(Chicken& chicken);
};