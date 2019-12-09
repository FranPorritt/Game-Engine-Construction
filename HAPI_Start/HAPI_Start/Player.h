#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	// YOU ARE HERE - TRYING TO MAKE PLAYER A SINGLETON SO CAN CONTROL INTERACTABLES. THINK THIS MAY BE UNNECESSARY, CONSULT CHAN
	static Player* _instance;
	Player();

	bool hasSeeds = false;

public:
	Player(const std::string& graphicIDArg, vector2<int> positionArg);
	~Player();
	static Player& GetInstance();

	void Direction();
};

#define PLAYER Player::GetInstance();