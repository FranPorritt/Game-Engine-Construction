#include "WanderingState.h"
#include "IdleState.h"
#include "Chicken.h"

ChickenState* WanderingState::Handle()
{
	return new IdleState();
}

void WanderingState::Enter()
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
			if (chicken.position.yPos > 180) // POSITION IS PROTECTED UH OH
			{
				chicken.direction = EDirection::eUp;
			}
			break;

		case 1:
			chicken.direction = EDirection::eDown;
			break;

		case 2:
			chicken.direction = EDirection::eLeft;
			break;

		case 3:
			chicken.direction = EDirection::eRight;
			break;

		case 4:
			chicken.direction = EDirection::eStop;
			break;
		}

		hasDirection = true;
	}
}
