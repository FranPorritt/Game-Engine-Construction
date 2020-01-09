#include <time.h>
#include <HAPI_lib.h>
#include <assert.h>

#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Chicken.h"
#include "Cat.h"
#include "Environment.h"
#include "SeedBox.h"
#include "Feeder.h"
#include "Coop.h"
#include "Interactables.h"
#include "Projectile.h"
#include "UserInterface.h"

using namespace HAPISPACE;

World::World()
{
}

World::~World()
{
	delete& player;
	delete& feeder;
	delete& seedBox;
	delete& rock;

	for (auto& entity : m_entities)
	{
		delete entity;
	}

	for (auto& chicken : m_chickenEntities)
	{
		delete chicken;
	}

	for (auto& cat : m_catEntities)
	{
		delete cat;
	}

	//delete this;
}

void World::Update()
{
	switch (currentState)
	{
	case GameState::eMenu:
		MainMenu();
		break;

	case GameState::ePlay:
		Play();
		break;

	case GameState::eQuit:
		Exit();
		break;

	case GameState::eRestart:
		Restart();
		break;

	default:
		break;
	}
}

bool World::Initialise()
{
	if (!LoadLevel())
		return false;

	UI.Initialise();

	HAPI.SetShowFPS(true);

	// Gets clock value for x seconds
	gameTimer = CLOCKS_PER_SEC * levelTime;
	rockClockLife = CLOCKS_PER_SEC * rockSecondsLife;

	return true;
}

bool World::LoadLevel()
{
	if (!VIS.CreateSprite("Data\\menu.png", "menuPage", 1, 1))
		return false;

	// Background Sprite
	if (!VIS.CreateSprite("Data\\environment.png", "background", 1, 1)) // BACKGROUND MAKE ENTITY
		return false;
	// Timer Sprite
	if (!VIS.CreateSprite("Data\\timer.png", "timer", 1, 1))
		return false;

	// Player Sprite
	if (!VIS.CreateSprite("Data\\player.png", "player", 1, 1)) // Last 2 ints for sprite sheets
		return false;

	// Chickens
	for (int chickenIndex = 0; chickenIndex < NUM_OF_CHICKENS; chickenIndex++)
	{
		if (!VIS.CreateSprite("Data\\White Chicken.png", "chicken" + std::to_string(chickenIndex), 1, 1))
			return false;
	}

	// Cats
	for (int catIndex = 0; catIndex < NUM_OF_CATS; catIndex++)
	{
		if (!VIS.CreateSprite("Data\\cat.png", "cat" + std::to_string(catIndex), 1, 1))
			return false;
	}

	// Fences Play Area
	if (!VIS.CreateSprite("Data\\fenceFront.png", "fenceFront", 1, 1))
		return false;
	if (!VIS.CreateSprite("Data\\fenceFront.png", "fenceBack", 1, 1))
		return false;
	if (!VIS.CreateSprite("Data\\fenceSide.png", "fenceLeft", 1, 1))
		return false;
	if (!VIS.CreateSprite("Data\\fenceSide.png", "fenceRight", 1, 1))
		return false;

	// Interactables
	if (!VIS.CreateSprite("Data\\seedEmpty.png", "seedBox", 1, 1))
		return false;
	if (!VIS.CreateSprite("Data\\feederEmpty.png", "feeder", 1, 1))
		return false;
	if (!VIS.CreateSprite("Data\\coop.png", "coop", 1, 1))
		return false;

	// Rock
	if (!VIS.CreateSprite("Data\\rock.png", "rock", 1, 1))
		return false;

	// Draw order
	m_entities.push_back(new Environment("fenceBack", { 180, 176 }));
	m_entities.push_back(new Environment("fenceLeft", { 191, 205 }));
	m_entities.push_back(new Environment("fenceRight", { 788, 205 }));
	m_entities.push_back(new SeedBox("seedBox", { 220, 190 }));
	m_entities.push_back(new Coop("coop", { 650, 200 }));
	m_entities.push_back(new Player("player", { 512, 384 }));
	m_entities.push_back(new Feeder("feeder", { 220, 570 }));
	m_entities.push_back(new Environment("fenceFront", { 180, 576 })); // Must be drawn after Player

	for (int chickenIndex = 0; chickenIndex < NUM_OF_CHICKENS; chickenIndex++)
	{
		m_chickenEntities.push_back(new Chicken("chicken" + std::to_string(chickenIndex), { rand() % 550 + 200, rand() % 350 + 200 }));
	}

	for (int catIndex = 0; catIndex < NUM_OF_CATS; catIndex++)
	{
		m_catEntities.push_back(new Cat("cat" + std::to_string(catIndex), { -50, rand() % 350 + 200 }));
	}

	rock = new Projectile("rock", { 0,0 }); // Only one, player can only thrown one at a time

	for (auto& entity : m_entities)
	{
		VIS.CreateSourceRect(entity->GetID());
		entity->CreateRect(VIS.GetSpriteHeight(entity->GetID()), VIS.GetSpriteWidth(entity->GetID()));

		if (entity->GetSide() == ESide::eSidePlayer)
		{
			player = entity;
		}
		else if (entity->GetSide() == ESide::eSideSeed)
		{
			seedBox = entity;
		}
		else if (entity->GetSide() == ESide::eSideFeeder)
		{
			feeder = entity;
		}
		else if (entity->GetSide() == ESide::eSideCoop)
		{
			coop = entity;
		}
	}

	for (auto& chicken : m_chickenEntities)
	{
		VIS.CreateSourceRect(chicken->GetID());
		chicken->CreateRect(VIS.GetSpriteHeight(chicken->GetID()), VIS.GetSpriteWidth(chicken->GetID()));
	}

	for (auto& cat : m_catEntities)
	{
		VIS.CreateSourceRect(cat->GetID());
		cat->CreateRect(VIS.GetSpriteHeight(cat->GetID()), VIS.GetSpriteWidth(cat->GetID()));
	}

	VIS.CreateSourceRect(rock->GetID());
	rock->CreateRect(VIS.GetSpriteHeight(rock->GetID()), VIS.GetSpriteWidth(rock->GetID()));

	return true;
}

void World::Run()
{
	while (HAPI.Update())
	{
		Update();
	}
}

void World::MainMenu()
{
	HAPI_TColour clearScreenCol = HAPI_TColour::BLACK;
	VIS.ClearToColour(clearScreenCol);

	while ((HAPI.Update()) && (currentState == GameState::eMenu))
	{
		const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

		VIS.DrawBackgroundSprite("menuPage", 0, 0);

		if (keyData.scanCode['1'])
		{
			currentState = GameState::ePlay;
		}
		else if (keyData.scanCode['2'])
		{
			HAPI.Close();
			// Doesn't delete stuff - causing memory leaks :(
		}
	}
}

void World::Play()
{
	gameStartTime = clock(); // Gets clock value when game starts, minus from currentTime for game timer

	HAPI_TColour clearScreenCol = HAPI_TColour::BLACK;
	VIS.ClearToColour(clearScreenCol);

	while ((HAPI.Update()) && (currentState == GameState::ePlay))
	{
		const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
		const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);

		currentTime = clock();

		if (keyData.scanCode['Q']) // very sensitive -- can pause and unpause in a split second :( also doesn't pause timer :(:(
		{
			isPaused = !isPaused;
		}

		if ((!timesUp) && (!isPaused))
		{
			if (keyData.scanCode['E'])
			{
				Interaction();
			}
			if (controllerData.isAttached)
			{
				if (controllerData.digitalButtons[HK_DIGITAL_A])
				{
					Interaction();
				}
			}

			if ((keyData.scanCode['F']) && (numOfRocks > 0))
			{
				Throw();
			}
			if (controllerData.isAttached)
			{
				if (controllerData.digitalButtons[HK_DIGITAL_B])
				{
					Throw();
				}
			}

			if (currentTime >= callTime + tickRate)
			{
				VIS.ClearToColour(clearScreenCol);
				VIS.DrawBackgroundSprite("background", 0, 0);

				// Game Timer + UI
				int timerValue = levelTime - ((currentTime - gameStartTime) / CLOCKS_PER_SEC);
				UI.GameTimer(timerValue);
				UI.Controls();
				UI.EggScore(eggsCollected);
				UI.RockCounter(numOfRocks);

				if (eggsInCoop > 0)
				{
					UI.EggCoop();
				}

				if (static_cast<SeedBox*>(seedBox)->GetSeed())
				{
					// Draws empty sprite with full sprite on top -- has to be drawn above player
					VIS.DrawSprite(seedBox->GetID(), seedBox->GetPos().xPos, seedBox->GetPos().yPos);
					UI.SeedFull();
				}
				else
				{
					// Seed box timer -- can this be moved to UI? (wouldn't be able to use sprite code???)
					VIS.DrawTimerSprite("timer", 220, 165, static_cast<SeedBox*>(seedBox)->GetTimerPercent());
					VIS.DrawSprite(seedBox->GetID(), seedBox->GetPos().xPos, seedBox->GetPos().yPos);
				}

				// Draws entities every frame + collisions
				for (auto& entity : m_entities)
				{
					vector2<int> currentPos = entity->GetPos();
					entity->Update();

					// COLLISIONS
					for (auto& entity2 : m_entities)
					{
						// Check entitys aren't same side
						if ((entity2 != entity) && (entity2->GetSide() != entity->GetSide()))
						{
							if (entity->Collision(*entity, *entity2))
							{
								// Environment types made a weird invisible wall halfway through play area??? Need to fix properly :(
								if ((entity->GetType() != EType::eTypeEnvironment) && (entity2->GetType() != EType::eTypeEnvironment))
								{
									entity->SetPos(currentPos);
								}
							}
						}
					}

					VIS.DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);

					// Draws interactables with different states seperately for each state
					if (entity->GetSide() == ESide::eSideSeed)
					{
						if (static_cast<SeedBox*>(seedBox)->GetSeed())
						{
							// Draws empty sprite with full sprite on top -- has to be drawn above player
							VIS.DrawSprite(seedBox->GetID(), seedBox->GetPos().xPos, seedBox->GetPos().yPos);
							UI.SeedFull();
						}
						else
						{
							// Seed box timer -- can this be moved to UI? (wouldn't be able to use sprite code???)
							VIS.DrawTimerSprite("timer", 220, 165, static_cast<SeedBox*>(seedBox)->GetTimerPercent());
							VIS.DrawSprite(seedBox->GetID(), seedBox->GetPos().xPos, seedBox->GetPos().yPos);
						}
					}
					else if (entity->GetSide() == ESide::eSideFeeder)
					{
						if (static_cast<Feeder*>(feeder)->GetSeed())
						{
							UI.FeederFull();
						}
						else
						{
							VIS.DrawSprite(feeder->GetID(), feeder->GetPos().xPos, feeder->GetPos().yPos);
						}
					}
				}

				// CHICKEN AI - Draw/State Checks
				for (auto& chicken : m_chickenEntities)
				{
					if (chicken->GetFlag())
					{
						VIS.DrawSprite(chicken->GetID(), chicken->GetPos().xPos, chicken->GetPos().yPos);
						chicken->Movement();
					}

					if (chicken->GetEating())
					{
						static_cast<Feeder*>(feeder)->Eat();
						chicken->SetEating();
					}

					if (chicken->laidEgg)
					{
						eggsInCoop++;
						chicken->laidEgg = false;
					}

					if (chicken->isFleeing)
					{
						chicken->Handle();
					}

					// Immediately calls new state when circumstances change - ie. food all gone, chickens stopping heading for it
					chicken->isFeederFull = static_cast<Feeder*>(feeder)->GetSeed();
					if (chicken->isFeederFull != chicken->lastFeederState)
					{
						chicken->Handle();
						chicken->lastFeederState = chicken->isFeederFull;
					}
				}

				// Cat Draw
				for (auto& cat : m_catEntities)
				{
					VIS.DrawSprite(cat->GetID(), cat->GetPos().xPos, cat->GetPos().yPos);
					cat->Movement();
				}

				// PROJECTILE
				if (rock->GetFlag())
				{
					VIS.DrawSprite(rock->GetID(), rock->GetPos().xPos, rock->GetPos().yPos);
					rock->Movement();

					// Checks cat collisions only while rock is active
					for (auto& cat : m_catEntities)
					{
						if (cat->Collision(*cat, *rock))
						{
							cat->SetHit(1);
							cat->Handle();
						}
					}

					if (currentTime >= rockCallTime + rockClockLife)
					{
						rock->SetFlag(0);
					}
				}
				else // rock changes direction mid throw otherwise
				{
					rock->SetDir(static_cast<Player*>(player)->GetLastDir()); // Gets players last direction, ignores stop -- throws in last direction player was heading
				}

				callTime = clock();
			}

			// CHICKEN STATES	
			if (currentTime >= chickenCallTime + chickenRate)
			{
				for (auto& chicken : m_chickenEntities)
				{
					if (currentTime >= chickenCallTime + chicken->GetRate())
					{
						chicken->isFeederFull = static_cast<Feeder*>(feeder)->GetSeed();
						chicken->lastFeederState = chicken->isFeederFull;

						chicken->Handle();
						chickenCallTime = clock();
					}
				}
			}

			// CAT STATES
			if (currentTime >= catCallTime + catRate)
			{
				for (auto& cat : m_catEntities)
				{
					int uniqueCatRate = rand() % 100; // offsets and randomises cat times

					if (currentTime >= catCallTime + uniqueCatRate)
					{
						cat->SetFlag(1);

						if (!cat->CheckTarget()) // Checks cat doesn't already have target
						{
							cat->FindChicken(m_chickenEntities[rand() % NUM_OF_CHICKENS]);
						}

						cat->Handle();
						catCallTime = clock();
					}
				}
			}

		}

		/*	if ((static_cast<Player*>(player)->GetLastDir() != EDirection::eStop))
			{
				HAPI.PlaySound("Data\\Sound\\footsteps.wav");
			}*/

			// Game over / Times up
		if ((currentTime - gameStartTime) >= gameTimer)
		{
			timesUp = true;
			UI.TimesUp();

			if (keyData.scanCode['R'])
			{
				currentState = GameState::eRestart;
			}
		}
	}
}

void World::Exit()
{
	// Pause menu needs implementing
}

void World::Restart()
{
	m_entities.clear();
	m_chickenEntities.clear();
	m_catEntities.clear();

	LoadLevel();
	currentState = GameState::eMenu;
	Run();
}

void World::Interaction()
{
	for (auto& interactable : m_entities)
	{
		if (interactable->GetType() == EType::eTypeInteractable)
		{
			if (static_cast<Interactables*>(interactable)->InteractButtonPressed()) // Checks if player is trying to interact with this object (collision function)
			{
				// Which object determines response.
				switch (interactable->GetSide())
				{
				case ESide::eSideSeed:
					if (static_cast<SeedBox*>(interactable)->GetSeed()) // Checks seeder has seed available
					{
						static_cast<SeedBox*>(interactable)->SetSeedFalse(); // 'Empties' seed box
						SeedInteract(1); // Gives player seeds
					}
					break;

				case ESide::eSideFeeder:
					if (static_cast<Player*>(player)->GetSeeds()) // Checks player has seeds
					{
						static_cast<Feeder*>(interactable)->SetSeedTrue(); // 'Fills' feeder
						SeedInteract(0); // Takes players seeds

						for (auto& chicken : m_chickenEntities)
						{
							chicken->isFeederFull = static_cast<Feeder*>(feeder)->GetSeed();
							chicken->Handle();
						}
					}
					break;

				case ESide::eSideCoop:
					CollectEgg();
					break;

				default:
					break;
				}
			}
		}
	}
}

void World::SeedInteract(const int& value)
{
	static_cast<Player*>(player)->SetSeeds(value);
}

void World::CollectEgg()
{
	eggsCollected += eggsInCoop;
	eggsInCoop = 0;
}

void World::Throw()
{
	if (!rock->GetFlag()) // Rock isn't active
	{
		HAPI.PlaySound("Data\\Sound\\rock throw.wav");
		rock->SetFlag(1); // Sets flag to true
		rock->SetPos(player->GetPos());
		numOfRocks--;
		rockCallTime = clock();
	}
}