#include "Coop.h"

Coop::Coop(const std::string& graphicIDArg, vector2<int> positionArg) : Interactables(graphicIDArg, positionArg)
{
	side = ESide::eSideCoop;
	type = EType::eTypeInteractable;
}

Coop::~Coop()
{
}