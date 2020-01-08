#include "LeavingState.h"
#include "InactiveState.h"
#include "Cat.h"

CatState* LeavingState::Handle(Cat& cat)
{
	cat.SetSpeed(3);

	if (!cat.GetFlag())
	{
		return new InactiveState();
	}

	return new LeavingState();
}

void LeavingState::Enter(Cat& cat)
{
	// WILL CONTROL GRAPHICS & SOUND AT SOME POINT
}

void LeavingState::Update(Cat& cat)
{
	if ((cat.GetPos().xPos > (0 - 40)) || (cat.GetPos().xPos < 1024)) // On screen
	{
		cat.SetSpeed(3);
		// On right of screen
		if (cat.GetPos().xPos >= (1024 / 2))
		{
			cat.direction = EDirection::eRight;
		}
		else
		{
			cat.direction = EDirection::eLeft;
		}
	}
	else
	{
		cat.SetFlag(0);
	}
}