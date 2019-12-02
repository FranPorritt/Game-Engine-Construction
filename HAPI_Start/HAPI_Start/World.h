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
	std::vector <Entity*> chickenEntities;

	clock_t currentTime = clock();
	clock_t callTime = clock(); // The time function was called
	clock_t chickenCallTime = clock(); 
	const double tickRate = 1000 / 60;
	const double chickenRate = 1000 / 30;

public:
	World();
	~World();

	bool Initialise();
	bool LoadLevel();
	void Run();
};
