#pragma once
#include "Interactables.h"

class SeedBox :	public Interactables
{
private:
	int seedRate = 50;
	int respawnRate = 10;
	int timer = 0;

	bool hasSeeds = true;

public:
	SeedBox(const std::string& graphicIDArg, vector2<int> positionArg);
	~SeedBox();

	void CreateInteractionBox() override final;
	void Update() override final;

	const bool InteractButtonPressed() override final { return isPlayerColliding; };

	const bool GetSeed() { return hasSeeds; };
	void SetSeedFalse() { hasSeeds = false; };
};
