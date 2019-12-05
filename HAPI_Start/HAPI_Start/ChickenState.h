#pragma once

class Chicken;
class IdleState;
class WanderingState;

class ChickenState
{
protected:

public:
	ChickenState();
	~ChickenState();

	virtual ChickenState* Handle(Chicken& chicken);
	virtual void Enter(Chicken& chicken);
	virtual void Update(Chicken& chicken);
};