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

public:
	bool isHungry = true;
	bool isFeederFull = false; // WILL BE SET BY A GETTER FROM FEEDER ENTITY

	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Handle();
	void Direction();

	vector2<int> GetPos() { return position; };
	int GetRate() { return chickenRate; };
};
