#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class UI
{
protected:

public:
	UI();
	~UI();

	bool Initialise();
	void GameTimer(int& timer);
	void TimesUp();
	void SeedFull();
	void FeederFull();
	void EggCoop();
	void EggScore(int& eggs);
	void RockCounter(int& rocks);
	void Controls();
};

