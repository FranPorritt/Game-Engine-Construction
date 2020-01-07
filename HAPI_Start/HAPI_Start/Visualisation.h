#pragma once
#include <HAPI_lib.h>
#include <unordered_map>
#include "Rectangle.h"

using namespace std;
using namespace HAPISPACE;

class Sprite;

class Visualisation
{	
private:
	static Visualisation* _instance;
	Visualisation();
protected:
	Rectangle destRect;

	int screenWidth = 0;
	int screenHeight = 0;
	BYTE* screen = nullptr;

	unordered_map<string, Sprite*> spriteMap;
	   
public:
	static Visualisation& GetInstance();
	~Visualisation();

	void ClearToColour(HAPI_TColour colour);

	bool CreateSprite(const string& filename, const string& name, int frameCol, int frameRow);
	void CreateSourceRect(const string& filename);
	void DrawBackgroundSprite(const string& name, int spriteX, int spriteY); // Doesn't check for clipping, improves framerate
	void DrawSprite(const string& name, int spriteX, int spriteY);
	void DrawTimerSprite(const string& name, int spriteX, int spriteY, float timerPercent);

	int GetScreenWidth() const { return screenWidth; }
	int GetScreenHeight() const { return screenHeight; }

	int GetSpriteWidth(const string& name) const;
	int GetSpriteHeight(const string& name) const;
};

#define VIS Visualisation::GetInstance()