#pragma once
#include "vector2.h"
#include <time.h>
#include <vector>
#include <string>
#include "Entity.h"

class ChickenState;
class IdleState;
class WanderingState;
class HungryState;

class Chicken :	public Entity
{
private:
	ChickenState* chickenState;
	ChickenState* state;
	int chickenRate = 0;

	bool isChickenEating = false;

public:
	// Passed into FSM -- Could make private and make getters/setters?
	bool isHungry = true;
	bool isFeederFull = false;
	bool lastFeederState = isFeederFull;

	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Handle();
	void Direction();
	void Eat();

	const vector2<int> GetPos() { return position; };
	const int GetRate() { return chickenRate; };
	const bool GetEating() { return isChickenEating; };
	void SetEating() { isChickenEating = false; };
};
