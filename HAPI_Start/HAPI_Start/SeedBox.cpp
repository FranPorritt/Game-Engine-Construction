#include "SeedBox.h"

SeedBox::SeedBox(const std::string& graphicIDArg, vector2<int> positionArg) : Interactables(graphicIDArg, positionArg)
{
	side = ESide::eSideSeed;
	type = EType::eTypeInteractable;
	viewOffset = 40;
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
			std::cout << "BOX has seeds" << std::endl;
			hasSeeds = true;
			timer = 0;
		}
		else
		{
			timer++;
			timerPercentage = ((float)timer / (float)respawnRate);
		}
	}
}