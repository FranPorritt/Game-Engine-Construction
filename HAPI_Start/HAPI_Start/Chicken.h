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

public:

	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Handle();
	void Direction();

	vector2 GetPos() { return position; };
};
