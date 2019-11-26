#include "Sprite.h"

Sprite::Sprite(int& frameCol, int& frameRow)
{
	frameCols = frameCol;
	frameRows = frameRow;
}

Sprite::~Sprite()
{
	delete[] data;
}

bool Sprite::Initialise(const string& filename)
{
	if (!HAPI.LoadTexture(filename, &data, spriteWidth, spriteHeight))
		return false;

	return true;
}

void Sprite::CreateRect()
{
	sourceRect.bottom = spriteHeight / frameRows;
	sourceRect.right = spriteWidth / frameCols;

	frameSizeHeight = spriteHeight / frameRows;
	frameSizeWidth = spriteWidth / frameCols;
}

void Sprite::Render(int spriteX, int spriteY, BYTE* screen, int screenWidth, int screenHeight)
{
	int offset = (spriteY * screenWidth + spriteX) * 4;

	BYTE* screenPntr = screen + offset;
	BYTE* texturePntr = data;

	int endOfLineScreenIncrement = (screenWidth - frameSizeWidth) * 4;

	for (int y = 0; y < frameSizeHeight; y++)
	{
		for (int x = 0; x < frameSizeWidth; x++)
		{
			BYTE blue = texturePntr[0];
			BYTE green = texturePntr[1];
			BYTE red = texturePntr[2];
			BYTE alpha = texturePntr[3];

			// Handles alpha special cases
			if (alpha == 255)
			{
				screenPntr[0] = blue;
				screenPntr[1] = green;
				screenPntr[2] = red;
			}
			else if (alpha > 0)
			{
				screenPntr[0] = screenPntr[0] + ((alpha * (blue - screenPntr[0])) >> 8);
				screenPntr[1] = screenPntr[1] + ((alpha * (green - screenPntr[1])) >> 8);
				screenPntr[2] = screenPntr[2] + ((alpha * (red - screenPntr[2])) >> 8);
			}

			screenPntr += 4;
			texturePntr += 4;
		}
		screenPntr += endOfLineScreenIncrement;
	}
}

void Sprite::ClipBlit(int& spriteX, int& spriteY, BYTE* screen, Rectangle& destRect)
{
	Rectangle clippedRect(sourceRect);
	clippedRect.Translate(spriteX, spriteY); // Converts to screen space to check if in/out of bounds

	if (!clippedRect.CompletelyOutside(destRect)) // if not completely outside
	{
		if (clippedRect.Inside(destRect))
		{
			Render(spriteX, spriteY, screen, destRect.Width(), destRect.Height());
		}
		else
		{
			clippedRect.ClipTo(destRect);
			clippedRect.Translate(-spriteX, -spriteY);

			if (spriteX < 0)
			{
				spriteX = 0;
			}
			if (spriteY < 0)
			{
				spriteY = 0;
			}

			int offset = (spriteY * destRect.Width() + spriteX) * 4;

			BYTE* screenPntr = screen + offset;
			BYTE* texturePntr = data + ((((size_t)clippedRect.left * 4) + ((size_t)clippedRect.top) * sourceRect.Width() * 4));	// Calculates clipped offset

			for (int y = 0; y < clippedRect.Height(); y++)
			{
				for (int x = 0; x < clippedRect.Width(); x++)
				{
					BYTE blue = texturePntr[0];
					BYTE green = texturePntr[1];
					BYTE red = texturePntr[2];
					BYTE alpha = texturePntr[3];

					// Handles alpha special cases
					if (alpha == 255)
					{
						screenPntr[0] = blue;
						screenPntr[1] = green;
						screenPntr[2] = red;
					}
					else if (alpha > 0)
					{
						screenPntr[0] = screenPntr[0] + ((alpha * (blue - screenPntr[0])) >> 8);
						screenPntr[1] = screenPntr[1] + ((alpha * (green - screenPntr[1])) >> 8);
						screenPntr[2] = screenPntr[2] + ((alpha * (red - screenPntr[2])) >> 8);
					}

					// Moves pointers to next pixel
					screenPntr += 4;
					texturePntr += 4; 
				}
				// Moves pointers to next line
				screenPntr += ((size_t)destRect.Width() - clippedRect.Width()) * 4;
				texturePntr += ((size_t)sourceRect.Width() - clippedRect.Width()) * 4; 
			}
		}
	}
}
