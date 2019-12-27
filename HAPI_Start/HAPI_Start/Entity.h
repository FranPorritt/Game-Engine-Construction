#pragma once
#include <string>
#include "vector2.h"
#include "Rectangle.h"
#include <HAPI_lib.h>

enum class EDirection
{
	eUp,
	eDown,
	eLeft,
	eRight,
	eStop,
};

enum class ESide
{
	eSidePlayer,	
	eSideSeed,
	eSideChicken,
	eSideNeutral,
	eSideFeeder,
};

enum class EType
{
	eTypeInteractable,
	eTypeAI,
	eTypeNeutral,
	eTypeEnvironment,
};

class Entity
{
protected:
	Rectangle rect;
	const std::string graphicID = nullptr;
	vector2<int> position = { 0,0 };
	int speed = 0;
	int health = 0;
	int viewOffset = 0;
	bool activeFlag = false;
	ESide side = ESide::eSideNeutral;
	EType type = EType::eTypeNeutral;

public:
	EDirection direction = EDirection::eStop;

	Entity();
	Entity(const std::string& graphicIDArg, vector2<int>& positionArg);
	~Entity();

	void CreateRect(int spriteHeight, int spriteWidth);
	virtual void Update();
	// Sets direction based on user input or ai
	virtual void Direction() = 0;
	// Moves entity based on direction
	void Movement();
	virtual bool Collision(Entity& entity1, Entity& entity2);
	void SetPos(vector2<int>& currentPos);

	vector2<int> GetPos() const { return position; };
	Rectangle GetRect() const { return rect; };
	std::string GetID() const { return graphicID; };
	ESide GetSide() const { return side; };
	EType GetType() const { return type; };
};

