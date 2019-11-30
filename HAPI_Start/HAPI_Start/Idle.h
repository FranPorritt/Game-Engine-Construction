#pragma once
#include "ChickenBehaviour.h"

class Chicken;

class Idle : public ChickenBehaviour
{
public:
	void Tick(Chicken& InChicken);
};

