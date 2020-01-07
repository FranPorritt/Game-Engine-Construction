#include "TransitionState.h"
#include "WanderingState.h"
#include "EggState.h"
#include "Chicken.h"

ChickenState* TransitionState::Handle(Chicken& chicken)
{
	chicken.SetSpeed(1);

	if ((!chicken.isHungry) && (isDoneTransitioning))
	{
		chicken.SetSpeed(2);
		return new EggState();
	}
	else if (isDoneTransitioning)
	{
		chicken.SetSpeed(1);
		return new WanderingState();
	}

	return new TransitionState();
}

void TransitionState::Enter(Chicken& chicken)
{
	isDoneTransitioning = false;
	randPos.xPos = rand() % 100 + 412;
	randPos.yPos = rand() % 100 + 284;
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void TransitionState::Update(Chicken& chicken)
{
	Direction(chicken);
}

void TransitionState::Direction(Chicken& chicken)
{
	xDistance = chicken.GetPos().xPos - randPos.xPos;
	if (xDistance < 0)
	{
		xDistance = -xDistance;
	}
	yDistance = chicken.GetPos().yPos - randPos.yPos;
	if (yDistance < 0)
	{
		yDistance = -yDistance;
	}

	if ((xDistance <= 3) && (yDistance <= 3))
	{
		isDoneTransitioning = true;
		chicken.direction = EDirection::eStop;
		chicken.Handle();
	}
	else
	{
		// Sets direction to feeder, prevents diagonal movement
		if (xDistance > yDistance)
		{
			if (randPos.xPos > chicken.GetPos().xPos)
			{
				chicken.direction = EDirection::eRight;
			}
			else
			{
				chicken.direction = EDirection::eLeft;
			}
		}
		else if (xDistance < yDistance)
		{
			if (randPos.yPos > chicken.GetPos().yPos)
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