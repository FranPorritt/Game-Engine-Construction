#include "Chicken.h"
#include "ChickenState.h"
#include "WanderingState.h"
#include "IdleState.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Chicken::Chicken(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 2;
	chickenState = new IdleState();
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
}

void Chicken::Direction()
{
	chickenState->Update(*this);
}
