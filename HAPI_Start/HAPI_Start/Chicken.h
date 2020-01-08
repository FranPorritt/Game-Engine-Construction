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
	// Passed into FSM -- Public because state machine has to change them
	bool isHungry = true;
	bool isFeederFull = false;
	bool laidEgg = false;
	bool lastFeederState = isFeederFull;
	bool isFleeing = false;

	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Handle();
	void Direction();
	void Eat();

	void SetEating() { isChickenEating = false; };
	void SetSpeed(const int& Speed) { speed = Speed; };
	void SetFlag(const int& value) { activeFlag = value; };

	const vector2<int> GetPos() { return position; };
	const int GetRate() { return chickenRate; };
	const bool GetEating() { return isChickenEating; };
};
