#pragma once
#include "ChickenState.h"
#include <vector>
#include "vector2.h"

class HungryState :	public ChickenState
{
protected:
	vector2<int> feederPos = { (rand()% 96 + 220) , 530 };

	int xFeederDistance = 0;
	int yFeederDistance = 0;

	bool isHeadingX = false;
	bool isHeadingY = false;

public:
	ChickenState* Handle(Chicken& chicken);
	void Enter(Chicken& chicken);
	void Update(Chicken& chicken);
	void Direction(Chicken& chicken);
};

