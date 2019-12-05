#include "IdleState.h"
#include "WanderingState.h"
#include "HungryState.h"
#include "Chicken.h"

ChickenState* IdleState::Handle(Chicken& chicken)
{
	if ((!chicken.isHungry) || (!chicken.isFeederFull))
	{
		return new WanderingState();
	}
	else if ((chicken.isHungry) && (chicken.isFeederFull))
	{
		return new HungryState();
	}
}

void IdleState::Enter(Chicken& chicken)
{
	// WILL CONTROL GRAPHICS AT SOME POINT, ECT.
}

void IdleState::Update(Chicken& chicken)
{
	chicken.direction = EDirection::eStop;
}
