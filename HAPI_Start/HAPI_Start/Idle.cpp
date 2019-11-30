#include "Idle.h"
#include "Chicken.h"

void Idle::Tick(Chicken& InChicken)
{
	InChicken.direction = EDirection::eStop;
}
