#pragma once
#include "Entity.h"

// FSM States
// Idle/Inactive - Not active
// Hunting - Heading to chicken -- Get chicken pos
// Leaving - Ate chicken/Hit by rock -- Pick random direction and leave

class CatState;
class Chicken;

class Cat :	public Entity
{
private:
	CatState* catState;
	CatState* state;

	Chicken* chickenTarget;

	bool hasTarget = false;
	bool isHit = false;
public:
	Cat(const std::string& graphicIDArg, vector2<int> positionArg);
	~Cat();

	void Handle();
	void Direction() override;
	bool Collision(Entity& entity1, Entity& entity2) override final;

	void SetFlag(const int& value) { activeFlag = value; };
	void SetSpeed(const int& Speed) { speed = Speed; };
	void SetHit(const int& hit) { isHit = hit; }
	void FindChicken(Chicken* chicken);

	Chicken* GetChickenTarget() { return chickenTarget; };
	const bool CheckTarget() { return hasTarget; };
	const bool GetHit() { return isHit; };
};

