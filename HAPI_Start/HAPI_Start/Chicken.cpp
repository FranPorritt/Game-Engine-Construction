#include "Chicken.h"
#include "ChickenState.h"
#include "WanderingState.h"
#include "IdleState.h"
#include "HungryState.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Chicken::Chicken(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 1;
	chickenState = new IdleState();
	chickenRate = rand() % 300 + 600;
}

Chicken::~Chicken()
{
}

void Chicken::Handle()
{
	ChickenState* state = chickenState->Handle();
	if (state != NULL)
	{
		delete chickenState;
		chickenState = state;
	}

	chickenState->Enter();
}

void Chicken::Direction()
{
	chickenState->Update();
}
