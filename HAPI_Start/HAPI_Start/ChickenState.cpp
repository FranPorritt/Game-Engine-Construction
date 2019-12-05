#include "ChickenState.h"
#include "Chicken.h"
#include "IdleState.h"
#include "WanderingState.h"
#include "HAPI_lib.h"

using namespace HAPISPACE;

ChickenState::ChickenState()
{
}

ChickenState::~ChickenState()
{
}

ChickenState* ChickenState::Handle(Chicken& chicken)
{
	return 0;
}

void ChickenState::Enter(Chicken& chicken)
{
}

void ChickenState::Update(Chicken& chicken)
{
}
