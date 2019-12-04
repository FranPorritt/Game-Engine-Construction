#pragma once
#include "ChickenState.h"
#include <vector>
#include "vector2.h"

class HungryState :	public ChickenState
{
protected:
	vector2<int> feederPos = { 235 , 530 };

	int xFeederDistance = 0;
	int yFeederDistance = 0;

	bool isHeadingX = false;
	bool isHeadingY = false;

public:
	ChickenState* Handle();
	void Enter();
	void Update(Chicken& chicken);
	void Direction(Chicken& chicken);
};

