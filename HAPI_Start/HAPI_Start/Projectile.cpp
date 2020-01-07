#include "Projectile.h"

Projectile::Projectile(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	type = EType::eTypeProjectile;
	side = ESide::eSidePlayer;
	speed = 6;
	activeFlag = false;
}

Projectile::~Projectile()
{
}

void Projectile::Direction()
{
	direction = playerDir;

	if (position.xPos <= 0 || position.xPos >= 1024 || position.yPos <= 0 || position.yPos >= 768) // MAGIC NUMBERS - PASS IN FROM VIS
	{
		activeFlag = false;
	}
}

void Projectile::SetPos(vector2<int>& pos)
{
	position = pos;
}

void Projectile::SetDir(EDirection direction)
{
	if (direction != EDirection::eStop) // Accounts for playing standing still
	{
		playerDir = direction;
	}
}