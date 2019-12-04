#include "IdleState.h"
#include "WanderingState.h"
#include "HungryState.h"
#include "Chicken.h"

ChickenState* IdleState::Handle()
{
	if ((!isHungry) || (!isFeederFull))
	{
		return new WanderingState();
	}
	else if ((isHungry) && (isFeederFull))
	{
		return new HungryState();
	}
}

void IdleState::Enter()
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void IdleState::Update(Chicken& chicken)
{
	chicken.direction = EDirection::eStop;
}
