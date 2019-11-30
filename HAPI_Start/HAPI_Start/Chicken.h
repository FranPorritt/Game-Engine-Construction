#pragma once
#include <vector>
#include <string>
#include "Entity.h"

class Behaviour;

class Chicken :	public Entity
{
public:
	Chicken(const std::string& graphicIDArg, vector2<int> positionArg);
	~Chicken();

	void Tick(Behaviour& behaviour);
	void Direction();
};


// COMPLETELY CHANGING CHICKEN MOVEMENT
//
// RATHER THAN CONSTANT WAYPOINTS, JUST HAVE CHICKENS MOVE A LITTLE BIT THEN PAUSE THEN MOVE A LITTLE BIT SOMEWHERE ELSE
// NO SPORADIC RUNNING AROUND CONSTANTLY ALWAYS MOVING TO A NEW GOAL -- JUST NICE CHILL CHICKENS
