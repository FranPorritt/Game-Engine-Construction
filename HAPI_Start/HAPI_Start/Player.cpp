#include "Player.h"

using namespace HAPISPACE;

Player::Player(const std::string& graphicIDArg, vector2<int> positionArg) : Entity(graphicIDArg, positionArg)
{
	speed = 3;
}

Player::~Player()
{
}

void Player::Direction()
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

	//  Set enum
	if ((keyData.scanCode['W']) && (position.yPos > 180)) // MAGIC NUMBERS
	{
		if ((position.xPos < 230) && (position.yPos < 210)) // FIND A BETTER WAY OF STOPPING PLAYER WALKING ON TOP OF OBJECTS
		{
			direction = EDirection::eStop;
		}
		else
		{
			direction = EDirection::eUp;
		}
	}
	else if ((keyData.scanCode['S']) && (position.yPos < 560))
	{
		direction = EDirection::eDown;
	}
	else if ((keyData.scanCode['A']) && (position.xPos > 205))
	{
		direction = EDirection::eLeft;
	}
	else if (keyData.scanCode['D'] && (position.xPos < 760))
	{
		direction = EDirection::eRight;
	}
	else
	{
		direction = EDirection::eStop;
	}

	// Controller Input
	const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);
	if (controllerData.isAttached)
	{
		if ((controllerData.digitalButtons[HK_DIGITAL_DPAD_UP]) && (position.yPos > 180))
		{
			direction = EDirection::eUp;
		}
		if ((controllerData.digitalButtons[HK_DIGITAL_DPAD_DOWN]) && (position.yPos < 560))
		{
			direction = EDirection::eDown;
		}
		if ((controllerData.digitalButtons[HK_DIGITAL_DPAD_LEFT]) && (position.xPos > 205))
		{
			direction = EDirection::eLeft;
		}
		if ((controllerData.digitalButtons[HK_DIGITAL_DPAD_RIGHT]) && (position.xPos < 760))
		{
			direction = EDirection::eRight;
		}
	}
}
