#include "HungryState.h"
#include "WanderingState.h"
#include "EggState.h"
#include "TransitionState.h"
#include "Chicken.h"

ChickenState* HungryState::Handle(Chicken& chicken)
{
	if ((chicken.isHungry) && (!chicken.isFeederFull))
	{
		return new WanderingState();
	}
	else if (!chicken.isHungry)
	{
		return new TransitionState();
	}
	else if ((chicken.isHungry) && (chicken.isFeederFull))
	{
		return new HungryState();
	}
}

void HungryState::Enter(Chicken& chicken)
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void HungryState::Update(Chicken& chicken)
{
	Direction(chicken);
}

void HungryState::Direction(Chicken& chicken)
{
	xFeederDistance = chicken.GetPos().xPos - feederPos.xPos;
	if (xFeederDistance < 0)
	{
		xFeederDistance = -xFeederDistance;
	}
	yFeederDistance = chicken.GetPos().yPos - feederPos.yPos;
	if (yFeederDistance < 0)
	{
		yFeederDistance = -yFeederDistance;
	}

	if ((xFeederDistance <= 3) && (yFeederDistance <= 3))
	{
		chicken.isHungry = false; // CHANGE TO EATSTATE ONCE IMPLEMENTED
		chicken.direction = EDirection::eStop;
	}
	else
	{
		// Sets direction to feeder, prevents diagonal movement
		if (xFeederDistance > yFeederDistance)
		{
			if (feederPos.xPos > chicken.GetPos().xPos)
			{
				chicken.direction = EDirection::eRight;
			}
			else
			{
				chicken.direction = EDirection::eLeft;
			}
		}
		else if (xFeederDistance < yFeederDistance)
		{
			if (feederPos.yPos > chicken.GetPos().yPos)
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

