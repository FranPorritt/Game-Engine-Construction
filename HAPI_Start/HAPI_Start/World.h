#pragma once
#include <time.h>
#include <iostream>
#include <vector>

class Visualisation;
class Entity;

class World
{
private:
	std::shared_ptr<Visualisation> m_vis;
	std::vector <Entity*> entities; // maybe make map??

	clock_t currentTime = clock();
	clock_t callTime = clock(); // Time function was called
	const double tickRate = 1000 / 60;

public:
	World();
	~World();

	bool Initialise();
	bool LoadLevel();
	void Run();
};

