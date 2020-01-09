#include "InactiveState.h"
#include "HuntingState.h"
#include "LeavingState.h"
#include "Cat.h"

CatState* InactiveState::Handle(Cat& cat)
{
	if (cat.GetFlag())
	{
		return new HuntingState();
	}
	else if (cat.GetHit())
	{
		return new LeavingState();
	}

	return new InactiveState();
}

void InactiveState::Enter(Cat& cat)
{
	// WILL CONTROL GRAPHICS & SOUND AT SOME POINT
}

void InactiveState::Update(Cat& cat)
{
	cat.direction = EDirection::eStop;
}