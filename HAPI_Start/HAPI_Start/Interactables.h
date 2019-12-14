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

	void CreateInteractionBox();
	void Direction() override final;
	// Only called when player has pressed interaction button
	virtual void Interact() = 0;
	bool Collision(Entity& entity1, Entity& entity2) override final;
};

