#pragma once
#include "Interactables.h"

class Feeder :	public Interactables
{
private:
	int seedHealth = 0;

	bool hasSeeds = false;

public:
	Feeder(const std::string& graphicIDArg, vector2<int> positionArg);
	~Feeder();

	void Update() override final;
	void Eat();

	const bool InteractButtonPressed() override final { return isPlayerColliding; };
	void SetSeedTrue();

	const bool GetSeed() { return hasSeeds; };
};

