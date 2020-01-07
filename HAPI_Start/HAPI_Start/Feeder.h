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

	void Eat();

	void SetSeedTrue();

	const bool GetSeed() { return hasSeeds; };
};

