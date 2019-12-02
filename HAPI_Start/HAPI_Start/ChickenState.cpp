#include "ChickenState.h"
#include "IdleState.h"
#include "WanderingState.h"

ChickenState::ChickenState()
{
	idle = new IdleState();
	wandering = new WanderingState();
}