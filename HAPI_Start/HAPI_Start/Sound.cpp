#include "Sound.h"

Sound* Sound::_instance{ nullptr };

Sound& Sound::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Sound;
	}

	return *_instance;
}

Sound::Sound()
{
	// Load sounds
	HAPI.LoadSound("Data\\Sound\\CatMeow.wav");
}

Sound::~Sound()
{
}