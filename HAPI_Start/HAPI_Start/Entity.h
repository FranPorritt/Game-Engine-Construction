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

class Entity
{
protected:
	EDirection direction = EDirection::eStop;
	Rectangle rect;
	const std::string graphicID = NULL;
	vector2<int> position = { 0,0 };
	int speed = 0;
	int health = 0;
	bool activeFlag = false;

public:
	Entity(const std::string& graphicIDArg, vector2<int>& positionArg);
	~Entity();

	void CreateRect(int spriteHeight, int spriteWidth);
	void Update();
	// Sets direction based on user input or ai
	virtual void Direction() = 0;
	// Moves entity based on direction
	void Movement();

	vector2<int> GetPos() { return position; };
	std::string GetID() { return graphicID; };
};

