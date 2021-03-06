#pragma once
#include "CatState.h"

class LeavingState : public CatState
{
public:
	CatState* Handle(Cat& cat);
	void Enter(Cat& cat);
	void Update(Cat& cat);
};

