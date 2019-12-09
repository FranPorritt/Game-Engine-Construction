#include "Environment.h"

Environment::Environment(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	side = ESide::eSideEnvironment;
}

Environment::~Environment()
{
}

void Environment::Direction()
{
	direction = EDirection::eStop;
}
