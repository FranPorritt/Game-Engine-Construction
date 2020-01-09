#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class UserInterface
{
private:
	static UserInterface* _instance;
	UserInterface();

public:
	static UserInterface& GetInstance();
	~UserInterface();

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

#define UI UserInterface::GetInstance()