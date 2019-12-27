#include "Chicken.h"
#include "ChickenState.h"
#include "WanderingState.h"
#include "IdleState.h"
#include "HungryState.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Chicken::Chicken(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	side = ESide::eSideChicken;
	speed = 1;
	chickenState = new IdleState();
	state = new IdleState();
}

Chicken::~Chicken()
{
}

void Chicken::Handle()
{
	chickenRate = rand() % 250 + 100;

	state = chickenState->Handle(*this);
	if (state != chickenState)
	{
		if (state != NULL)
		{
			delete chickenState;
			chickenState = state;
			chickenState->Enter(*this);
		}
	}
}

void Chicken::Direction()
{
	chickenState->Update(*this);
}

void Chicken::Eat()
{
	isChickenEating = true;
}
