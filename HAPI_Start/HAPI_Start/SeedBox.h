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

	void Update();
	void Interact() override final;

	bool GetSeed() { return hasSeeds; };
};
