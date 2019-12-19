#pragma once
#include "Interactables.h"

class Feeder :	public Interactables
{
private:
	bool hasSeeds = false;

public:
	Feeder(const std::string& graphicIDArg, vector2<int> positionArg);
	~Feeder();

	void CreateInteractionBox() override final;
	void Update() override final;

	const bool InteractButtonPressed() override final { return isPlayerColliding; };

	const bool GetSeed() { return hasSeeds; };
	void SetSeedFalse() { hasSeeds = false; };
};

