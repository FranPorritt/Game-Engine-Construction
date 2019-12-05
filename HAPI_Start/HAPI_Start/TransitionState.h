#pragma once
#include "vector2.h"
#include "ChickenState.h"

class TransitionState :	public ChickenState
{
private:
	vector2<int> randPos = { 0,0 };

	int xDistance = 0;
	int yDistance = 0;

	bool isDoneTransitioning = false;
	
private:
	ChickenState* Handle(Chicken& chicken);
	void Enter(Chicken& chicken);
	void Update(Chicken& chicken);
	void Direction(Chicken& chicken);
};

