#pragma once
#include <time.h>
#include <iostream>
#include <vector>
#include "vector2.h"

class Visualisation;
class Entity;
class Chicken;
class Interactables;

class World
{
private:
	std::shared_ptr<Visualisation> m_vis;
	std::vector <Entity*> m_entities; // maybe make map??
	std::vector <Chicken*> m_chickenEntities;

	clock_t currentTime = clock();
	clock_t callTime = clock(); // The time function was called
	clock_t chickenCallTime = clock(); 
	const double tickRate = 1000 / 60;
	int chickenRate = rand() % 200 + 200; // Make this a random between range

public:
	World();
	~World();

	bool Initialise();
	bool LoadLevel();
	void Run();

	void Interaction();
	void SeedInteract();
};

