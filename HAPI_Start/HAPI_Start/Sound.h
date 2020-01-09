#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Sound
{
private:
	static Sound* _instance;
	Sound();

protected:


public:
	static Sound& GetInstance();
	~Sound();
};

#define SFX Sound::GetInstance()