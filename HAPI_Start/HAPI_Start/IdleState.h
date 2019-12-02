#pragma once
#include "ChickenBehaviour.h"

class Chicken;

class IdleState : public ChickenBehaviour
{
public:
	void Tick(Chicken& InChicken);
};

