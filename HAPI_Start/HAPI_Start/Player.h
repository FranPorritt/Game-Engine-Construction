#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	Player();

	EDirection lastDirection = EDirection::eStop;

	bool hasSeeds = false;

public:
	Player(const std::string& graphicIDArg, vector2<int> positionArg);
	~Player();

	void Direction() override final;

	void SetSeeds(const int& value) { hasSeeds = value; std::cout << "PLAYER seeds" << value << std::endl; };

	EDirection GetLastDir() const { return direction; };
	bool GetSeeds() const { return hasSeeds; };
};