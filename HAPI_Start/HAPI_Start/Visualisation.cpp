#include "Visualisation.h"
#include "Sprite.h"

Visualisation::Visualisation()
{
	screenWidth = 1024;
	screenHeight = 768;
	if (!HAPI.Initialise(screenWidth, screenHeight, "Francesca Porritt - V8078659"))
		return;

	destRect.bottom = screenHeight;
	destRect.right = screenWidth;

	screen = HAPI.GetScreenPointer();
}

Visualisation::~Visualisation()
{
	for (auto& p : spriteMap)
		delete p.second;
}

void Visualisation::ClearToColour(HAPI_TColour colour)
{
	BYTE* temp = screen;
	for (int pixelIndex = 0; pixelIndex < (screenWidth * screenHeight); pixelIndex++)
	{
		memcpy(temp, &colour, 4);
		temp += 4;
	}
}

bool Visualisation::CreateSprite(const string& filename, const string& name)
{
	Sprite* newSprite = new Sprite(); 
	if (!newSprite->Initialise(filename))
	{
		HAPI.UserMessage("uh oh, spaghetti-o! File not found!", "Error");
		return false;
	}

	spriteMap[name] = newSprite;

	return true;
}

void Visualisation::CreateSourceRect(const string& name)
{
	spriteMap[name]->CreateRect();
}

void Visualisation::DrawBackgroundSprite(const string& name, int spriteX, int spriteY)
{
#if defined(__DEBUG)
	if (spriteMap.find(name) == spriteMap.end())
	{
		cerr << "uh oh, spaghetti-o" << endl;
	}
#endif

	spriteMap[name]->Render(spriteX, spriteY, screen, screenWidth, screenHeight);
}

void Visualisation::DrawSprite(const string& name, int spriteX, int spriteY)
{
#if defined(__DEBUG)
	if (spriteMap.find(name) == spriteMap.end())
	{
		cerr << "uh oh, spaghetti-o" << endl;
	}
#endif

	spriteMap[name]->ClipBlit(spriteX, spriteY, screen, destRect);
}

int Visualisation::GetSpriteWidth(const string& name) const
{
	return spriteMap.at(name)->GetSpriteWidth();
}

int Visualisation::GetSpriteHeight(const string& name) const
{
	return spriteMap.at(name)->GetSpriteHeight();
}



