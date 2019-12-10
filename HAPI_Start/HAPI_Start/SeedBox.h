#pragma once
#include "Entity.h"

class SeedBox :	public Entity
{
private:
	Rectangle interactionBox;
	int seedRate = 50;
	int respawnRate = 10;
	int timer = 0;

	bool hasSeeds = true;

public:
	SeedBox(const std::string& graphicIDArg, vector2<int> positionArg);
	~SeedBox();

	void CreateInteractionBox();
	void Update();
	void Direction();

	bool GetSeed() { return hasSeeds; };
};
