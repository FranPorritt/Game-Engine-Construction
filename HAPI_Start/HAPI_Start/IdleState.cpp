#include "IdleState.h"
#include "WanderingState.h"
#include "Chicken.h"

ChickenState* IdleState::Handle()
{
	return new WanderingState();
}

void IdleState::Enter()
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void IdleState::Update(Chicken& chicken)
{
	chicken.direction = EDirection::eStop;
}
