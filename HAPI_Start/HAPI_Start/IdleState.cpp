#include "IdleState.h"
#include "Chicken.h"

void IdleState::Tick(Chicken& InChicken)
{
	InChicken.direction = EDirection::eStop;
}
