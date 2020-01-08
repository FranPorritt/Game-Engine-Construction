#include "InactiveState.h"
#include "HuntingState.h"
#include "Cat.h"

CatState* InactiveState::Handle(Cat& cat)
{
	if (cat.GetFlag())
	{
		return new HuntingState();
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