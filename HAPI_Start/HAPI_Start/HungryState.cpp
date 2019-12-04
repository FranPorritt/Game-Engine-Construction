#include "HungryState.h"
#include "WanderingState.h"
#include "Chicken.h"

ChickenState* HungryState::Handle()
{
	if ((!isHungry) || (!isFeederFull))
	{
		return new WanderingState();
	}
	else if ((!isHungry) && (!isFeederFull))
	{
		return new HungryState();
	}
}

void HungryState::Enter()
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void HungryState::Update(Chicken& chicken)
{
	if (isHungry)
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
		isHungry = false; // CHANGE TO EATSTATE ONCE IMPLEMENTED
		chicken.direction = EDirection::eStop;
	}
	else
	{
		// Sets direction to feeder, prevents diagonal movement
		if ((xFeederDistance > yFeederDistance) && (!isHeadingY))
		{
			isHeadingX = true;

			if (feederPos.xPos > chicken.GetPos().xPos)
			{
				chicken.direction = EDirection::eRight;
			}
			else
			{
				chicken.direction = EDirection::eLeft;
			}

			if (xFeederDistance <= 4)
			{
				isHeadingX = false;
			}
		}
		else if ((xFeederDistance < yFeederDistance) && (!isHeadingX))
		{
			isHeadingY = true;

			if (feederPos.yPos > chicken.GetPos().yPos)
			{
				chicken.direction = EDirection::eDown;
			}
			else
			{
				chicken.direction = EDirection::eUp;
			}

			if (yFeederDistance <= 4)
			{
				isHeadingY = false;
			}
		}
	}
}

