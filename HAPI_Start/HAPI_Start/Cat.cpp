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

bool Cat::Collision(Entity& entity1, Entity& entity2)
{
	int right1 = entity1.GetRect().right + entity1.GetPos().xPos;
	int left1 = entity1.GetRect().left + entity1.GetPos().xPos;
	int top1 = entity1.GetRect().top + entity1.GetPos().yPos;
	int bottom1 = entity1.GetRect().bottom + entity1.GetPos().yPos;

	int right2 = entity2.GetRect().right + entity2.GetPos().xPos;
	int left2 = entity2.GetRect().left + entity2.GetPos().xPos;
	int top2 = entity2.GetRect().top + entity2.GetPos().yPos;
	int bottom2 = entity2.GetRect().bottom + entity2.GetPos().yPos;

		if ((right1 < left2) || (left1 > right2) || (bottom1 < top2) || (top1 > bottom2))
		{
			return false; // No collision
		}
		else
		{
			return true;
		}
}

void Cat::FindChicken(Chicken* chicken)
{
	hasTarget = true;
	chickenTarget = chicken;
}