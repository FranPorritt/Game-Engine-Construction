#pragma once

class Cat;

class CatState
{
public:
	CatState();
	~CatState();

	virtual CatState* Handle(Cat& cat);
	virtual void Enter(Cat& cat);
	virtual void Update(Cat& cat);
};

