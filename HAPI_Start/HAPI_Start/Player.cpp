#include "Player.h"

using namespace HAPISPACE;

Player::Player(const std::string& graphicIDArg) : Entity(graphicIDArg)
{
}

Player::~Player()
{
}

void Player::Direction()
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	HAPI.SetShowFPS(true);

	//  Set enum
	if ((keyData.scanCode['W']))
	{
		direction = EDirection::eUp;
	}
	if ((keyData.scanCode['S']))
	{
		direction = EDirection::eDown;
	}
	if ((keyData.scanCode['A']))
	{
		direction = EDirection::eLeft;
	}
	if (keyData.scanCode['D'])
	{
		direction = EDirection::eRight;
	}

	// Controller Input
	const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);
	if (controllerData.isAttached)
	{
		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_UP])
		{
			direction = EDirection::eUp;
		}
		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_DOWN])
		{
			direction = EDirection::eDown;
		}
		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_LEFT])
		{
			direction = EDirection::eLeft;
		}
		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
		{
			direction = EDirection::eRight;
		}
	}
}
