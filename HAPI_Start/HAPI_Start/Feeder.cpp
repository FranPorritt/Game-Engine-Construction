#include "Feeder.h"

Feeder::Feeder(const std::string& graphicIDArg, vector2<int> positionArg) : Interactables(graphicIDArg, positionArg)
{
	side = ESide::eSideFeeder;
	type = EType::eTypeInteractable;
}

Feeder::~Feeder()
{
	delete this;
}

void Feeder::Update()
{
	// once 2 chickens have interacted -- not full
	// ie. health = 2, chicken eat - 1 health, if health = 0, not full
}

void Feeder::Eat()
{
	if (seedHealth == 0)
	{
		std::cout << "NO SEEDS" << std::endl;
		hasSeeds = false;
	}
	else
	{
		seedHealth--;
	}
}

void Feeder::SetSeedTrue()
{
	hasSeeds = true; 
	seedHealth = 2;
	std::cout << "FEEDER has seeds" << std::endl;
}