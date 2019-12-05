#include "EggState.h"
#include "WanderingState.h"
#include "TransitionState.h"

ChickenState* EggState::Handle(Chicken& chicken)
{
	if (!chicken.isHungry)
	{
		return new EggState();
	}

	return new TransitionState();
}

void EggState::Enter(Chicken& chicken)
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void EggState::Update(Chicken& chicken)
{
	Direction(chicken);
}

void EggState::Direction(Chicken& chicken)
{
	xCoopDistance = chicken.GetPos().xPos - coopPos.xPos;
	if (xCoopDistance < 0)
	{
		xCoopDistance = -xCoopDistance;
	}
	yCoopDistance = chicken.GetPos().yPos - coopPos.yPos;
	if (yCoopDistance < 0)
	{
		yCoopDistance = -yCoopDistance;
	}

	if ((xCoopDistance <= 3) && (yCoopDistance <= 3))
	{
		chicken.isHungry = true; // CHANGE TO EATSTATE ONCE IMPLEMENTED
		chicken.isFeederFull = false; // TEST - REMOVE
		chicken.direction = EDirection::eStop;
	}
	else
	{
		// Sets direction to feeder, prevents diagonal movement
		if (xCoopDistance > yCoopDistance)
		{
			if (coopPos.xPos > chicken.GetPos().xPos)
			{
				chicken.direction = EDirection::eRight;
			}
			else
			{
				chicken.direction = EDirection::eLeft;
			}
		}
		else if (xCoopDistance < yCoopDistance)
		{
			if (coopPos.yPos > chicken.GetPos().yPos)
			{
				chicken.direction = EDirection::eDown;
			}
			else
			{
				chicken.direction = EDirection::eUp;
			}
		}
	}
}
