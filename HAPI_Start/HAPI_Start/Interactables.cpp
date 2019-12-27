#include "Interactables.h"

Interactables::Interactables(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	type = EType::eTypeInteractable;
	side = ESide::eSideNeutral;
}

Interactables::~Interactables()
{
}

void Interactables::Direction()
{
	direction = EDirection::eStop;
}

bool Interactables::Collision(Entity& entity1, Entity& entity2)
{
	int right1 = interactionBox.right + position.xPos;
	int left1 = interactionBox.left + position.xPos;
	int top1 = interactionBox.top + position.yPos;
	int bottom1 = interactionBox.bottom + position.yPos;

	int right2 = entity2.GetRect().right + entity2.GetPos().xPos;
	int left2 = entity2.GetRect().left + entity2.GetPos().xPos;
	int top2 = entity2.GetRect().top + entity2.GetPos().yPos;
	int bottom2 = entity2.GetRect().bottom + entity2.GetPos().yPos;

	if (top2 < 384) // Top half of screen
	{
		if ((right1 < left2) || (left1 > right2) || (bottom1 < top2 - viewOffset) || (top1 > bottom2 - viewOffset))
		{
			if (entity2.GetSide() == ESide::eSidePlayer)
			{
				isPlayerColliding = false;
			}
			return false; // No collision
		}
		else
		{
			if (entity2.GetSide() == ESide::eSidePlayer)
			{
				isPlayerColliding = true;
			}
			return true;
		}
	}
	else // Bottom half of screen
	{
		if ((right1 < left2) || (left1 > right2) || (bottom1 < top2 + (viewOffset / 2)) || (top1 > bottom2 + (viewOffset / 2)))
		{
			if (entity2.GetSide() == ESide::eSidePlayer)
			{
				isPlayerColliding = false;
			}
			return false; // No collision
		}
		else
		{
			if (entity2.GetSide() == ESide::eSidePlayer)
			{
				isPlayerColliding = true;
			}
			return true;
		}
	}
}