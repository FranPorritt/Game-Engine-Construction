#include "Entity.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Entity::Entity()
{
}

Entity::Entity(const std::string& graphicIDArg, vector2<int>& positionArg) : graphicID(graphicIDArg), position(positionArg)
{
}

Entity::~Entity()
{
}

void Entity::CreateRect(int spriteHeight, int spriteWidth)
{
	rect.bottom = spriteHeight;
	rect.right = spriteWidth;
}

void Entity::Update()
{
	Movement();
}

void Entity::Movement()
{
	Direction();

	switch (direction)
	{
	case EDirection::eUp:
		position.yPos -= speed;
		break;

	case EDirection::eDown:
		position.yPos += speed;
		break;

	case EDirection::eLeft:
		position.xPos -= speed;
		break;

	case EDirection::eRight:
		position.xPos += speed;
		break;

	case EDirection::eStop:
		break;

	default:
		break;
	}
}

bool Entity::Collision(Entity& entity1, Entity& entity2)
{
	int right1 = entity1.rect.right + entity1.position.xPos;
	int left1 = entity1.rect.left + entity1.position.xPos;
	int top1 = entity1.rect.top + entity1.position.yPos;
	int bottom1 = entity1.rect.bottom + entity1.position.yPos;

	int right2 = entity2.rect.right + entity2.position.xPos;
	int left2 = entity2.rect.left + entity2.position.xPos;
	int top2 = entity2.rect.top + entity2.position.yPos;
	int bottom2 = entity2.rect.bottom + entity2.position.yPos;


	if ((right1 < left2) || (left1 > right2) || (bottom1 < top2 - viewOffset) || (top1 > bottom2 - viewOffset))
	{
		return false; // No collision
	}
	else
	{
		return true;
	}
}

void Entity::PlayerInteract(Entity& entity1, Entity& entity2)
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	// COLLISION TYPES:
	// PLAYER:
	// - SEED
	// - FEEDER
	// - COOP

	switch (entity2.GetSide())
	{
	case ESide::eSideSeed:
		if (keyData.scanCode['E'])
		{

		}
		break;

	default:
		break;
	}
}

void Entity::SetPos(vector2<int>& currentPos)
{
	position = currentPos;
}
