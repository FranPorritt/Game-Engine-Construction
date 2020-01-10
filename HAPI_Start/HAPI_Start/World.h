#pragma once
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "vector2.h"

class Visualisation;
class Entity;
class Chicken;
class Cat;
class Interactables;
class Projectile;
class UserInterface;

enum class GameState
{
	eMenu,
	ePlay,
	eQuit,
	eRestart,
	// Pause, Restart, Win/Lose?
};

class World
{
private:
	GameState currentState = GameState::eMenu;
	
	std::vector <Entity*> m_entities;
	std::vector <Chicken*> m_chickenEntities;
	std::vector <Cat*> m_catEntities;

	Entity* player = NULL;
	Entity* seedBox = NULL;
	Entity* feeder = NULL;
	Entity* coop = NULL;
	Projectile* rock = NULL;

	clock_t gameStartTime = clock();
	clock_t currentTime = clock();
	clock_t callTime = clock(); // The time function was called
	clock_t chickenCallTime = clock(); 
	clock_t catCallTime = clock();
	clock_t rockCallTime = clock();
	clock_t pauseStartTime = clock();
	clock_t pauseEndTime = clock();
	const double tickRate = 1000 / 60;
	int chickenRate = rand() % 200 + 200;
	int catRate = rand() % 200 + 200;
	int pausedTime = 0;

	const int NUM_OF_CHICKENS = 10;
	const int NUM_OF_CATS = 8;

	const int rockSecondsLife = 1; // Time in secs
	int rockClockLife = 0; // Time in clock value

	int numOfRocks = 10; // Isn't const -- tracks player throws

	int eggsInCoop = 0;
	int eggsCollected = 0;

	int gameTimer = 0;  // Time in clock value
	const int levelTime = 60; // Time in seconds
	bool timesUp = false;

	bool isPaused = false;
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
	void Restart();

	void Interaction();
	void SeedInteract(const int& value);
	void CollectEgg();
	void Throw();
};

