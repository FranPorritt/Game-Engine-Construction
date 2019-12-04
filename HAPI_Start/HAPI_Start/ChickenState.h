#pragma once

class Chicken;
class IdleState;
class WanderingState;

class ChickenState
{
protected:
	static bool isHungry;
	static bool isFeederFull; // MAYBE MOVE ELSEWHERE -- IN OWN ENTITY IDK

public:
	ChickenState();
	~ChickenState();

	virtual ChickenState* Handle();
	virtual void Enter();
	virtual void Update();
};