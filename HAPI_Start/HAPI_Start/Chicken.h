#pragma once
#include <vector>
#include "Entity.h"

class Chicken :	public Entity
{
private:
	std::vector<vector2<int>> waypoints; // A vector of vector2s
	vector2<int> targetWaypoint = { 0,0 };

	const int numOfRandWaypoints = 5;

	bool hasReachedDestination = true;

public:
	Chicken(const std::string& graphicIDArg, vector2<int>& positionArg);
	~Chicken();

	void InitialiseWaypoints();
	void SelectWaypoint();
	void Direction();
};

