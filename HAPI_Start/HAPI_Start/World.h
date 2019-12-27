#pragma once
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "vector2.h"

class Visualisation;
class Entity;
class Chicken;
class Interactables;

enum class GameState
{
	eMenu,
	ePlay,
	eQuit,
	// Pause, Restart, Win/Lose?
};

class World
{
private:
	GameState currentState = GameState::eMenu;

	std::shared_ptr<Visualisation> m_vis;

	std::vector <Entity*> m_entities;
	std::vector <Chicken*> m_chickenEntities;
	//std::vector <std::string> ui; // Holds sprite names

	Entity* player = NULL;
	Entity* seedBox = NULL;
	Entity* feeder = NULL;

	clock_t gameStartTime = clock();
	clock_t currentTime = clock();
	clock_t callTime = clock(); // The time function was called
	clock_t chickenCallTime = clock(); 
	const double tickRate = 1000 / 60;
	int chickenRate = rand() % 200 + 200; // Make this a random between range

	int gameTimer = 0;
	int levelTime = 30;
	bool timesUp = false;

public:
	World();
	~World();

	void Update();
	bool Initialise();
	bool LoadLevel();
	void Run();

	void MainMenu();
	void Play();
	void Exit();

	void Interaction();
	void SeedInteract(const int& value);
};

