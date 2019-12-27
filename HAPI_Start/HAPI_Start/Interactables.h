#pragma once
#include "Entity.h"

class Interactables : public Entity
{
protected:
	Rectangle interactionBox;

	bool isPlayerColliding = false;

public:
	Interactables(const std::string& graphicIDArg, vector2<int> positionArg);
	~Interactables();

	void Direction() override final;	
	virtual const bool InteractButtonPressed() = 0; // Only called when player has pressed interaction button
	bool Collision(Entity& entity1, Entity& entity2) override final;
};

