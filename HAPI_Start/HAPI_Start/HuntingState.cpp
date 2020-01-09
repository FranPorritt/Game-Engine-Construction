#include "HuntingState.h"
#include "InactiveState.h"
#include "LeavingState.h"
#include "Cat.h"
#include "Chicken.h"

CatState* HuntingState::Handle(Cat& cat)
{
	cat.SetSpeed(1);

	if ((reachedTarget) || (cat.GetHit()))
	{
		return new LeavingState();
	}

	return new HuntingState();
}

void HuntingState::Enter(Cat& cat)
{
	if (rand() % 20 == 0)
	{
		HAPI.PlaySound("Data\\Sound\\meow.wav");
	}
}

void HuntingState::Update(Cat& cat)
{
	Direction(cat);
}

void HuntingState::Direction(Cat& cat)
{
	Chicken* chicken = cat.GetChickenTarget();

	xTargetDistance = cat.GetPos().xPos - chicken->GetPos().xPos;
	if (xTargetDistance < 0)
	{
		xTargetDistance = -xTargetDistance;
	}
	yTargetDistance = cat.GetPos().yPos - chicken->GetPos().yPos;
	if (yTargetDistance < 0)
	{
		yTargetDistance = -yTargetDistance;
	}

	// Triggers chickens fleeingState
	if ((xTargetDistance <= 60) && (yTargetDistance <= 60) && (!chicken->isFleeing)) // and chicken isn't already fleeing
	{
		chicken->isFleeing = true;
	}
	else
	{
		chicken->isFleeing = false;
	}

	if ((xTargetDistance <= 3) && (yTargetDistance <= 3))
	{
		chicken->SetFlag(0); // Kills chicken 
		reachedTarget = true;
		cat.Handle();
	}
	else
	{
		// Sets direction to feeder, prevents diagonal movement
		if (xTargetDistance > yTargetDistance)
		{
			if (chicken->GetPos().xPos > cat.GetPos().xPos)
			{
				cat.direction = EDirection::eRight;
			}
			else
			{
				cat.direction = EDirection::eLeft;
			}
		}
		else if (xTargetDistance < yTargetDistance)
		{
			if (chicken->GetPos().yPos > cat.GetPos().yPos)
			{
				cat.direction = EDirection::eDown;
			}
			else
			{
				cat.direction = EDirection::eUp;
			}
		}
	}
}