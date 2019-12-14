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
	void Interaction(Entity& entity2);

	void SetSeedsTrue() { hasSeeds = true; };
	void SetSeedsFalse() { hasSeeds = false; };
};