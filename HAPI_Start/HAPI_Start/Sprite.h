#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"

using namespace std;
using namespace HAPISPACE;

class Sprite
{
protected:
	Rectangle sourceRect;

	int spriteWidth = 0;
	int spriteHeight = 0;
	BYTE* data = nullptr;

public:
	Sprite();
	~Sprite();

	bool Initialise(const string& filename);
	void CreateRect();
	void Render(int spriteX, int spriteY, BYTE* screen, int screenWidth, int screenHeight);
	void ClipBlit(int& spriteX, int& spriteY, BYTE* screen, Rectangle& destRect);

	int GetSpriteWidth() const { return spriteWidth; }
	int GetSpriteHeight() const { return spriteHeight; }
};

