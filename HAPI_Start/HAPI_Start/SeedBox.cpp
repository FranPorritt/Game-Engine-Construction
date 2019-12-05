#include "SeedBox.h"

SeedBox::SeedBox(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
}

SeedBox::~SeedBox()
{
}

void SeedBox::Update()
{
	if (!hasSeeds)
	{
		if (timer == respawnRate)
		{
			hasSeeds = true;
			timer = 0;
		}
		else
		{
			timer++;
		}
	}
}

void SeedBox::Direction()
{
	direction = EDirection::eStop;
}