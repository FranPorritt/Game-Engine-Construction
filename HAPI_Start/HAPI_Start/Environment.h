#pragma once
#include "Entity.h"
class Environment :	public Entity
{
public:
	Environment(const std::string& graphicIDArg, vector2<int> positionArg);
	~Environment();

	void Direction();
};

