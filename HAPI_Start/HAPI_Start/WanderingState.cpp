#include "WanderingState.h"
#include "IdleState.h"
#include "HungryState.h"
#include "FleeingState.h"
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
	else if (chicken.isFleeing)
	{
		return new FleeingState();
	}

	return new WanderingState();
}

void WanderingState::Enter(Chicken& chicken)
{
	const int sound = rand() % 4;

	if (rand() % 4 == 0)
	{
		switch (sound)
		{
		case 0:
			HAPI.PlaySound("Data\\Sound\\cluck.flac");
			break;

		case 1:
			HAPI.PlaySound("Data\\Sound\\cluck2.flac");
			break;

		case 2:
			HAPI.PlaySound("Data\\Sound\\cluck3.flac");
			break;

		case 3:
			HAPI.PlaySound("Data\\Sound\\cluck4.flac");
			break;

		default:
			break;
		}
	}

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
