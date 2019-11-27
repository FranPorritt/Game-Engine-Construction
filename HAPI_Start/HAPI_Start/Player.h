#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const std::string& graphicIDArg, vector2<int> positionArg);
	~Player();

	void Direction();
};

