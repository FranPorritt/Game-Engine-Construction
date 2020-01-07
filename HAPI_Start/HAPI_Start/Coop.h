#pragma once
#include "Interactables.h"

class Coop : public Interactables
{
public:
	Coop(const std::string& graphicIDArg, vector2<int> positionArg);
	~Coop();
};

