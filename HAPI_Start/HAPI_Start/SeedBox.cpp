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

void SeedBox::CreateInteractionBox()
{
	interactionBox.top = rect.bottom / 2; // Halfway up seed box sprite
	interactionBox.bottom = rect.bottom + interactionBox.top; // Goes belowe sprite
	interactionBox.left = rect.left;
	interactionBox.right = rect.right;
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