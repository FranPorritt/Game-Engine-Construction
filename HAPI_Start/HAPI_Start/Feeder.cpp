#include "Feeder.h"

Feeder::Feeder(const std::string& graphicIDArg, vector2<int> positionArg) : Interactables(graphicIDArg, positionArg)
{
	side = ESide::eSideFeeder;
	type = EType::eTypeInteractable;
}

Feeder::~Feeder()
{
}

void Feeder::CreateInteractionBox()
{
	interactionBox.top = 0 - (rect.bottom / 2);
	interactionBox.bottom = rect.bottom;
	interactionBox.left = rect.left;
	interactionBox.right = rect.right;
}

void Feeder::Update()
{
	// once 2 chickens have interacted -- not full
	// ie. health = 2, chicken eat - 1 health, if health = 0, not full
}