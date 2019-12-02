#pragma once

class IdleState;
class WanderingState;

class ChickenState
{
public:
	static IdleState* idle;
	static WanderingState* wandering;

	ChickenState();
	virtual void Tick();
};

