#include <time.h>
#include <HAPI_lib.h>
#include <assert.h>

#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Chicken.h"
#include "Environment.h"
#include "SeedBox.h"
#include "Feeder.h"
#include "Interactables.h"

using namespace HAPISPACE;

World::World()
{
}

World::~World()
{
	delete& m_vis;
	delete& player;
	delete& feeder;
	delete& seedBox;

	for (auto& entity : m_entities)
	{
		delete entity;
	}

	for (auto& chicken : m_chickenEntities)
	{
		delete chicken;
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

	default:
		break;
	}
}

bool World::Initialise()
{
	m_vis = std::make_shared<Visualisation>();
	if (!LoadLevel())
		return false;

	HAPI.SetShowFPS(true);

	gameTimer = CLOCKS_PER_SEC * levelTime;

	return true;
}

bool World::LoadLevel()
{
	if (!m_vis->CreateSprite("Data\\menu.png", "menuPage", 1, 1))
		return false;

	// Background Sprite
	if (!m_vis->CreateSprite("Data\\environment.png", "background", 1, 1)) // BACKGROUND MAKE ENTITY
		return false;
	// Timer Sprite
	if (!m_vis->CreateSprite("Data\\timer.png", "timer", 1, 1))
		return false;

	// Player Sprite
	if (!m_vis->CreateSprite("Data\\player.png", "player", 1, 1)) // Last 2 ints for sprite sheets
		return false;
	if (!m_vis->CreateSprite("Data\\White Chicken.png", "chicken", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\White Chicken.png", "chicken1", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\White Chicken.png", "chicken2", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\White Chicken.png", "chicken3", 1, 1))
		return false;

	// Fences Play Area
	if (!m_vis->CreateSprite("Data\\fenceFront.png", "fenceFront", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\fenceFront.png", "fenceBack", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\fenceSide.png", "fenceLeft", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\fenceSide.png", "fenceRight", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\seedEmpty.png", "seedBox", 1, 1))
		return false;
	if (!m_vis->CreateSprite("Data\\feederFull.png", "feeder", 1, 1))
		return false;

	// UI
	if (!m_vis->CreateSprite("Data\\Text\\timesup.png", "timesUpText", 1, 1))
		return false;

	//ui.push_back("timesUpText");

	// Draw order
	m_entities.push_back(new Environment("fenceBack", { 180, 176 }));
	m_entities.push_back(new Environment("fenceLeft", { 191, 205 }));
	m_entities.push_back(new Environment("fenceRight", { 788, 205 }));
	m_entities.push_back(new SeedBox("seedBox", { 220, 190 }));
	m_entities.push_back(new Player("player", { 512, 384 }));
	m_entities.push_back(new Feeder("feeder", { 220, 570 }));
	m_entities.push_back(new Environment("fenceFront", { 180, 576 })); // Must be drawn after Player

	m_chickenEntities.push_back(new Chicken("chicken", { 560, 384 }));
	m_chickenEntities.push_back(new Chicken("chicken1", { 430, 480 }));
	m_chickenEntities.push_back(new Chicken("chicken2", { 650, 290 }));
	m_chickenEntities.push_back(new Chicken("chicken3", { 390, 384 }));

	for (auto& entity : m_entities)
	{
		m_vis->CreateSourceRect(entity->GetID());
		entity->CreateRect(m_vis->GetSpriteHeight(entity->GetID()), m_vis->GetSpriteWidth(entity->GetID()));

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
	}

	for (auto& chicken : m_chickenEntities)
	{
		m_vis->CreateSourceRect(chicken->GetID());
		chicken->CreateRect(m_vis->GetSpriteHeight(chicken->GetID()), m_vis->GetSpriteWidth(chicken->GetID()));
	}

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
	m_vis->ClearToColour(clearScreenCol);

	while ((HAPI.Update()) && (currentState == GameState::eMenu))
	{
		const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();

		m_vis->DrawBackgroundSprite("menuPage", 0, 0);

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
	m_vis->ClearToColour(clearScreenCol);

	while ((HAPI.Update()) && (currentState == GameState::ePlay))
	{
		const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
		currentTime = clock();

		if (!timesUp)
		{
			if (keyData.scanCode['E'])
			{
				Interaction();
			}

			if (currentTime >= callTime + tickRate)
			{
				m_vis->ClearToColour(clearScreenCol);
				m_vis->DrawBackgroundSprite("background", 0, 0);
				//m_vis->DrawTimerSprite("timer", 220, 175, static_cast<SeedBox*>(seedBox)->GetTimerPercent());

				// Draws entities every frame
				for (auto& entity : m_entities)
				{
					vector2<int> currentPos = entity->GetPos();
					entity->Update();

					for (auto& entity2 : m_entities)
					{
						// Check entitys aren't same side
						if ((entity2 != entity) && (entity2->GetSide() != entity->GetSide()))
						{
							if (entity->Collision(*entity, *entity2))
							{
								if ((entity->GetType() != EType::eTypeEnvironment) && (entity2->GetType() != EType::eTypeEnvironment))
								{
									entity->SetPos(currentPos);
								}
							}
						}
					}

					m_vis->DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);

				}

				for (auto& chicken : m_chickenEntities)
				{
					m_vis->DrawSprite(chicken->GetID(), chicken->GetPos().xPos, chicken->GetPos().yPos);
					chicken->Movement();

					if (chicken->GetEating())
					{
						static_cast<Feeder*>(feeder)->Eat();
						chicken->SetEating();
					}

					// Immediately calls new state when circumstances change - ie. food all gone, chickens stopping heading for it
					chicken->isFeederFull = static_cast<Feeder*>(feeder)->GetSeed();
					if (chicken->isFeederFull != chicken->lastFeederState)
					{
						chicken->Handle();
						chicken->lastFeederState = chicken->isFeederFull;
					}
				}

				callTime = clock();
			}

			// Controls switch between wandering and idle chicken states		
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
		}
		else
		{
			for (auto& entity : m_entities)
			{
				m_vis->DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);
			}

			for (auto& chicken : m_chickenEntities)
			{
				m_vis->DrawSprite(chicken->GetID(), chicken->GetPos().xPos, chicken->GetPos().yPos);
			}
		}

		if ((currentTime - gameStartTime) >= gameTimer)
		{
			m_vis->DrawSprite("timesUpText", 312, 309);
			timesUp = true;
			std::cout << "TIME'S UP" << std::endl;
		}
	}
}

void World::Exit()
{

}

void World::Interaction()
{
	for (auto& interactable : m_entities)
	{
		if (interactable->GetType() == EType::eTypeInteractable)
		{
			if (static_cast<Interactables*>(interactable)->InteractButtonPressed()) // Checks if player is trying to interact with this object
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
