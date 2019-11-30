#include "Chicken.h"
#include "Behaviour.h"

Chicken::Chicken(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 2;

	//InitialiseWaypoints();
}

Chicken::~Chicken()
{
}

void Chicken::Tick(Behaviour& behaviour)
{
	behaviour->Tick();
}

void Chicken::Direction()
{	
	

	

	//// Gets x and y distances and makes them positive if negative
	//xTargetDistance = position.xPos - targetWaypoint.xPos;
	//if (xTargetDistance < 0)
	//{
	//	xTargetDistance = -xTargetDistance;
	//}
	//yTargetDistance = position.yPos - targetWaypoint.yPos;
	//if (yTargetDistance < 0)
	//{
	//	yTargetDistance = -yTargetDistance;
	//}

	//// Sets direction
	//if (xTargetDistance > yTargetDistance)
	//{
	//	if (targetWaypoint.xPos > position.xPos)
	//	{
	//		direction = EDirection::eRight;
	//	}
	//	else
	//	{
	//		direction = EDirection::eLeft;
	//	}
	//}
	//else
	//{
	//	if (targetWaypoint.yPos > position.yPos)
	//	{
	//		direction = EDirection::eDown;
	//	}
	//	else
	//	{
	//		direction = EDirection::eUp;
	//	}
	//}

	//SelectWaypoint(); // Sets a new target if destination has been reached
}
