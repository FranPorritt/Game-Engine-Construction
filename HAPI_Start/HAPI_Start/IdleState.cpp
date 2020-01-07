#include "IdleState.h"
#include "WanderingState.h"
#include "HungryState.h"
#include "Chicken.h"

ChickenState* IdleState::Handle(Chicken& chicken)
{
	chicken.SetSpeed(1);

	if ((!chicken.isHungry) || (!chicken.isFeederFull))
	{
		chicken.SetSpeed(1);
		return new WanderingState();
	}
	else if ((chicken.isHungry) && (chicken.isFeederFull))
	{
		chicken.SetSpeed(3);
		return new HungryState();
	}
}

void IdleState::Enter(Chicken& chicken)
{
	// WILL CONTROL GRAPHICS & SOUND AT SOME POINT
}

void IdleState::Update(Chicken& chicken)
{
	chicken.direction = EDirection::eStop;
}
