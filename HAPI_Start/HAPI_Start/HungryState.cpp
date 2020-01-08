#include "HungryState.h"
#include "WanderingState.h"
#include "EggState.h"
#include "IdleState.h"
#include "TransitionState.h"
#include "FleeingState.h"
#include "Chicken.h"

ChickenState* HungryState::Handle(Chicken& chicken)
{
	feederPos.xPos = (rand() % 96 + 220); // Width of sprite
	chicken.SetSpeed(2);

	if ((chicken.isHungry) && (!chicken.isFeederFull))
	{
		chicken.SetSpeed(1);
		return new WanderingState();
	}
	else if (!chicken.isHungry)
	{
		chicken.SetSpeed(1);
		return new TransitionState();
	}
	else if ((chicken.isHungry) && (chicken.isFeederFull))
	{
		chicken.SetSpeed(3);
		return new HungryState();
	}
	else if (chicken.isFleeing)
	{
		return new FleeingState();
	}
	else
	{
		chicken.SetSpeed(1);
		return new IdleState();
	}
}

void HungryState::Enter(Chicken& chicken)
{
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
		chicken.isHungry = false;
		chicken.direction = EDirection::eStop;
		chicken.Eat();
		chicken.Handle();
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

