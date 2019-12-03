#pragma once
#include "vector2.h"
#include <time.h>
#include <vector>
#include <string>
#include "Entity.h"

class ChickenState;
class Idle;
class Wandering;

class Chicken :	public Entity
{
private:
	ChickenState* chickenState;
	int chickenRate = 0;

public:

	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Handle();
	void Direction();

	vector2<int> GetPos() { return position; };
	int GetRate() { return chickenRate; };
};
