#include "Chicken.h"

Chicken::Chicken(const std::string& graphicIDArg, vector2<int>& positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 2;
}

Chicken::~Chicken()
{
}

void Chicken::InitialiseWaypoints()
{
	// Waypoints needed:
	// - Feeder
	// - Coop
	// - 5 Random points
	// [7 total]

	for (int wpIndex = 0; wpIndex < numOfRandWaypoints; wpIndex++)
	{
		int wpXPos = 200 + rand() % (780 - 200 + 1);
		int wpYPos = 186 + rand() % (566 - 186 + 1);

		waypoints.push_back({ wpXPos, wpYPos });
	}

	// INITIALISE FIRST TWO HERE AFTER THE RANDOMS -- ONCE YOU HAVE COORDS
}

void Chicken::SelectWaypoint()
{
	if (hasReachedDestination)
	{
		int randWaypoint = rand() % 6;

		targetWaypoint = waypoints[randWaypoint];
		hasReachedDestination = false;
	}

	if ((position.xPos == targetWaypoint.xPos) && (position.yPos == targetWaypoint.yPos)) // ISSUE: SPEED IS 2, MAY NEVER REACH EXACT POINT! DO IT BY RANGE INSTEAD
	{
		hasReachedDestination = true;
	}
}

void Chicken::Direction()
{	
	// LOOK AT SNAKE AI AND INTERPOLATION SLIDES
}
