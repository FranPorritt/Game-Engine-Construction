#pragma once
#include "ChickenState.h"
#include "Chicken.h"
#include "vector2.h"

class EggState : public ChickenState
{
protected:
	vector2<int> coopPos = { (rand() % 114 + 650) , 250 };

	int xCoopDistance = 0;
	int yCoopDistance = 0;

	bool isHeadingX = false;
	bool isHeadingY = false;

public:
	ChickenState* Handle(Chicken& chicken);
	void Enter(Chicken& chicken);
	void Update(Chicken& chicken);
	void Direction(Chicken& chicken);
};

