#include "Chicken.h"
#include "ChickenState.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Chicken::Chicken(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 2;
	chickenState = new ChickenState();
}

Chicken::~Chicken()
{
}

void Chicken::Tick(ChickenState* newChickenState)
{
	chickenState = newChickenState;
}

void Chicken::Direction()
{
}
