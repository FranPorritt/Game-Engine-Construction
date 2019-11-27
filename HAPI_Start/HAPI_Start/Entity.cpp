#include "Entity.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

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
