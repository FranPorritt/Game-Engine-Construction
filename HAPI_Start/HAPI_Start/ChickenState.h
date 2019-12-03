#pragma once

class Chicken;
class IdleState;
class WanderingState;

class ChickenState
{
public:

	ChickenState();
	~ChickenState();

	virtual ChickenState* Handle();
	virtual void Enter();
	virtual void Update(Chicken& chicken);
};

