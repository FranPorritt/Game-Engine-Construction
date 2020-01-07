#include "WanderingState.h"
#include "IdleState.h"
#include "HungryState.h"
#include "Chicken.h"

ChickenState* WanderingState::Handle(Chicken& chicken)
{
	chicken.SetSpeed(1);

	if ((chicken.isHungry) && (!chicken.isFeederFull))
	{
		chicken.SetSpeed(1);
		return new IdleState();
	}
	else if ((chicken.isHungry) && (chicken.isFeederFull))
	{
		chicken.SetSpeed(3);
		return new HungryState();
	}
}

void WanderingState::Enter(Chicken& chicken)
{
	hasDirection = false;
}

void WanderingState::Update(Chicken& chicken)
{
	if (!hasDirection)
	{
		int random = rand() % 5;

		switch (random)
		{
		case 0:
			if (chicken.GetPos().yPos > 180) 
				chicken.direction = EDirection::eUp;
			break;

		case 1:
			if (chicken.GetPos().yPos < 560)
				chicken.direction = EDirection::eDown;
			break;

		case 2:
			if (chicken.GetPos().xPos > 205)
				chicken.direction = EDirection::eLeft;
			break;

		case 3:
			if (chicken.GetPos().xPos < 760)
				chicken.direction = EDirection::eRight;
			break;

		case 4:
			chicken.direction = EDirection::eStop;

		default:
			break;
		}

		hasDirection = true;
	}
	else
	{
		if ((chicken.GetPos().yPos <= 200) && (chicken.direction == EDirection::eUp))
		{
			chicken.direction = EDirection::eDown;
			hasDirection = true;
			chicken.direction = EDirection::eStop;
		}

		if ((chicken.GetPos().yPos >= 545) && (chicken.direction == EDirection::eDown))
		{
			chicken.direction = EDirection::eUp;
			hasDirection = true;
			chicken.direction = EDirection::eStop;
		}

		if ((chicken.GetPos().xPos <= 225) && (chicken.direction == EDirection::eLeft))
		{
			chicken.direction = EDirection::eRight;
			hasDirection = true;
			chicken.direction = EDirection::eStop;
		}

		if ((chicken.GetPos().xPos >= 740) && (chicken.direction == EDirection::eRight))
		{
			chicken.direction = EDirection::eLeft;
			hasDirection = true;
			chicken.direction = EDirection::eStop;
		}
	}
}
