/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI:
	https://scm-intranet.tees.ac.uk/users/u0018197/hapi.html
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include <time.h>
#include "Visualisation.h"

// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

struct Player 
{
	int xPos = 0;
	int yPos = 0;
	int movementSpeed = 0;
};

void Movement(const HAPI_TKeyboardData& keyData, Player& playerPos, int& playerMin, int& playerMaxX, int& playerMaxY);

	bool rumbleOn = false;

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down
void HAPI_Main()
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	HAPI.SetShowFPS(true);
	
	Player playerPos;
	playerPos.xPos = 512;
	playerPos.yPos = 384;
	playerPos.movementSpeed = 1;

	HAPI_TColour clearScreenCol = HAPI_TColour::BLACK;
	Visualisation* vis = new Visualisation();
	vis->ClearToColour(clearScreenCol);

	// Creating sprites
	if (!vis->CreateSprite("Data\\spaceBackground.png", "background"))
		return;
	if (!vis->CreateSprite("Data\\playerSprite.tga", "player"))
		return;

	// Adds extra sprites to test clipping performance
	/*if (!vis->CreateSprite("Data\\playerSprite.tga", "player1"))
		return;
	if (!vis->CreateSprite("Data\\playerSprite.tga", "player2"))
		return;
	if (!vis->CreateSprite("Data\\playerSprite.tga", "player3"))
		return;*/

	vis->CreateSourceRect("player");

	//Extra test sprites
	/*vis->CreateSourceRect("player1");
	vis->CreateSourceRect("player2");
	vis->CreateSourceRect("player3");*/

	// Screen Bounds
	int playerMin = 0;
	int playerMaxX = vis->GetScreenWidth() - vis->GetSpriteWidth("player");
	int playerMaxY = vis->GetScreenHeight() - vis->GetSpriteHeight("player");

	while (HAPI.Update())
	{
		Movement(keyData, playerPos, playerMin, playerMaxX, playerMaxY);

		vis->ClearToColour(clearScreenCol);
		vis->DrawBackgroundSprite("background", 0, 0);
		vis->DrawSprite("player", playerPos.xPos, playerPos.yPos);

		// Extra test sprites
	/*	vis->DrawSprite("player1", -25, 250);
		vis->DrawSprite("player2", 500, 720);
		vis->DrawSprite("player3", 500, -10);*/

		// Rumbles controller if player passes over middle
		if ((playerPos.xPos < ((vis->GetScreenWidth() / 2) + 20) && (playerPos.xPos > ((vis->GetScreenWidth() / 2) - 20))) // xPos is between two middle points
			&& ((playerPos.yPos < ((vis->GetScreenHeight() / 2) + 20)) && (playerPos.yPos > ((vis->GetScreenHeight() / 2) - 20)))) // yPos is between two middle points
		{
			rumbleOn = true;
		}
		else
		{
			rumbleOn = false;
		}
	}
}

void Movement(const HAPI_TKeyboardData& keyData, Player& playerPos, int &playerMin, int &playerMaxX, int &playerMaxY)
{
	// SCREEN BOUND MOVEMENT
	/*if ((keyData.scanCode['W']) && (playerPos.yPos > playerMin))
	{
		playerPos.yPos--;
	}
	if ((keyData.scanCode['S']) && (playerPos.yPos < playerMaxY))
	{
		playerPos.yPos++;
	}
	if ((keyData.scanCode['A']) && (playerPos.xPos > playerMin))
	{
		playerPos.xPos--;
	}
	if ((keyData.scanCode['D']) && (playerPos.xPos < playerMaxX))
	{
		playerPos.xPos++;
	}*/

	// Controller Input
	const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);
	if (controllerData.isAttached)
	{
		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_DOWN])
		{
			playerPos.yPos += 2;
		}

		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_UP])
		{
			playerPos.yPos -= 2;
		}

		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
		{
			playerPos.xPos += 2;
		}

		if (controllerData.digitalButtons[HK_DIGITAL_DPAD_LEFT])
		{
			playerPos.xPos -= 2;
		}

		// Checks for rumble status
		if (rumbleOn)
		{
			HAPI.SetControllerRumble(0, 22000, 22000);
		}
		else
		{
			HAPI.SetControllerRumble(0, 0, 0);
		}
	}

	// Keyboard Input
	if ((keyData.scanCode['W']))
	{
		playerPos.yPos -= playerPos.movementSpeed;
	}
	if ((keyData.scanCode['S']))
	{
		playerPos.yPos += playerPos.movementSpeed;
	}
	if ((keyData.scanCode['A']))
	{
		playerPos.xPos -= playerPos.movementSpeed;
	}
	if (keyData.scanCode['D'])
	{
		playerPos.xPos += playerPos.movementSpeed;
	}
}
