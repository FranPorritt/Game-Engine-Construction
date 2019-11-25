#include "Entity.h"
#include <HAPI_lib.h>

using namespace HAPISPACE;

Entity::Entity(const std::string& graphicIDArg) : graphicID(graphicIDArg)
{
}

Entity::~Entity()
{
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
