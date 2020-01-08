#include "Cat.h"
#include "Chicken.h"
#include "CatState.h"
#include "InactiveState.h"

Cat::Cat(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	activeFlag = false;
	side = ESide::eSideCat;
	speed = 1;
	catState = new InactiveState();
	state = new InactiveState();
}

Cat::~Cat()
{
}

void Cat::Handle()
{
	state = catState->Handle(*this);
	if (state != catState)
	{
		if (state != NULL)
		{
			delete catState;
			catState = state;
			catState->Enter(*this);
		}
	}
}

void Cat::Direction()
{
	catState->Update(*this);
}

void Cat::FindChicken(Chicken* chicken)
{
	hasTarget = true;
	chickenTarget = chicken;
}