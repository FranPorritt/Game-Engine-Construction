#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const std::string& graphicIDArg);
	~Player();

	void Direction();
};

