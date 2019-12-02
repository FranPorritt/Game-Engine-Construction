#include "WanderingState.h"
#include "Chicken.h"

void WanderingState::Tick(Chicken& InChicken)
{
	const int randDir = rand() % 4;

	switch(randDir)
	{
	case 0:
		InChicken.direction = EDirection::eUp;
		break;

	case 1:
		InChicken.direction = EDirection::eDown;
		break;

	case 2:
		InChicken.direction = EDirection::eLeft;
		break;

	case 3:
		InChicken.direction = EDirection::eRight;
		break;

	default:
		break;
	}
}