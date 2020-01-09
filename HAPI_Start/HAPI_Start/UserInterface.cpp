#include "UserInterface.h"
#include "Visualisation.h"

UserInterface* UserInterface::_instance{ nullptr };

UserInterface& UserInterface::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new UserInterface;
	}

	return *_instance;
}

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

bool UserInterface::Initialise()
{
	if(!HAPI.ChangeFontFromFile("Data\\Text\\04B_30__.ttf"))
		return false;

	if (!VIS.CreateSprite("Data\\egg.png", "eggIcon", 1, 1))
		return false;

	if (!VIS.CreateSprite("Data\\seedFull.png", "seedFull", 1, 1))
		return false;

	if (!VIS.CreateSprite("Data\\feederFull.png", "feederFull", 1, 1))
		return false;

	return true;
}

void UserInterface::GameTimer(int& timer)
{
	// Display game timer correctly
	if (timer >= 10)
	{
		HAPI.RenderText(15, 30, HAPI_TColour::WHITE, "0:" + std::to_string(timer), 25, eRegular);
	}
	else
	{
		HAPI.RenderText(15, 30, HAPI_TColour::WHITE, "0:0" + std::to_string(timer), 25, eRegular);
	}
}

void UserInterface::TimesUp()
{
	HAPI.RenderText(255, 340, HAPI_TColour::MAGENTA, "TIME'S UP!", 60, eBold);
}

void UserInterface::SeedFull()
{
	VIS.DrawSprite("seedFull", 220, 210);
}

void UserInterface::FeederFull()
{
	VIS.DrawSprite("feederFull", 220, 570);
}

void UserInterface::EggCoop()
{
	VIS.DrawSprite("eggIcon", 690, 140);
}

void UserInterface::EggScore(int& eggs)
{
	HAPI.RenderText(375, 20, HAPI_TColour::WHITE, "EGGS: " + std::to_string(eggs), 40, eRegular);
}

void UserInterface::RockCounter(int& rocks)
{
	HAPI.RenderText(825, 30, HAPI_TColour::WHITE, "ROCKS: " + std::to_string(rocks), 25, eRegular);
}

void UserInterface::Controls()
{
	HAPI.RenderText(15, 700, HAPI_TColour::WHITE, "USE: E" , 20, eRegular);
	HAPI.RenderText(15, 730, HAPI_TColour::WHITE, "THROW: F", 20, eRegular);
}
