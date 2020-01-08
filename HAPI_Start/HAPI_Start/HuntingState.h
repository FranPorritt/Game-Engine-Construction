#pragma once
#include "CatState.h"

class Cat;
class Chicken;

class HuntingState : public CatState
{
private:
	int xTargetDistance = 0;
	int yTargetDistance = 0;

	bool reachedTarget = false;

public:
	CatState* Handle(Cat& cat);
	void Enter(Cat& cat);
	void Update(Cat& cat);
	void Direction(Cat& cat);
};

