#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	Player();

	bool hasSeeds = false;

public:
	Player(const std::string& graphicIDArg, vector2<int> positionArg);
	~Player();

	void Direction() override final;

	void SetSeeds(const int& value) { hasSeeds = value; std::cout << "PLAYER seeds" << value << std::endl; };

	bool GetSeeds() { return hasSeeds; };
};