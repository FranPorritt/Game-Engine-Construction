#pragma once
#include "Interactables.h"

class SeedBox :	public Interactables
{
private:
	int respawnRate = 500;
	int timer = 0;
	float timerPercentage = 0;

	bool hasSeeds = true;

public:
	SeedBox(const std::string& graphicIDArg, vector2<int> positionArg);
	~SeedBox();

	void Update() override final;

	const bool InteractButtonPressed() override final { return isPlayerColliding; };

	const float GetTimerPercent() { return timerPercentage; };
	const bool GetSeed() { return hasSeeds; };
	void SetSeedFalse() { hasSeeds = false; std::cout << "BOX has NO seeds" << std::endl; };
};
