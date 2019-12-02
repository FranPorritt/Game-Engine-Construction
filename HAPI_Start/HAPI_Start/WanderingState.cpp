#include "WanderingState.h"
#include "IdleState.h"
#include "Chicken.h"

ChickenState* WanderingState::Handle()
{
	return new IdleState();
}

void WanderingState::Update(Chicken& chicken)
{
	int random = rand() % 5;

	switch (random)
	{
	case 0:
		chicken.direction = EDirection::eUp;
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
}
