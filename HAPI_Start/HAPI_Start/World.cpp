#include "World.h"
#include <HAPI_lib.h>
#include "Visualisation.h"
#include "Player.h"
#include "Chicken.h"
#include "Environment.h"
#include <time.h>

using namespace HAPISPACE;

World::World()
{
}

World::~World()
{
	// delete entities
}

bool World::Initialise()
{
	m_vis = std::make_shared<Visualisation>();
	if (!LoadLevel())
		return false;

	HAPI.SetShowFPS(true);

	return true;
}

bool World::LoadLevel()
{
	// Background Sprite
	if (!m_vis->CreateSprite("Data\\environment.png", "background", 1, 1)) // BACKGROUND MAKE ENTITY
		return false;

	// Player Sprite
	if (!m_vis->CreateSprite("Data\\player.png", "player", 4, 4)) // Last 2 ints for sprite sheets
		return false;
	if (!m_vis->CreateSprite("Data\\White Chicken.png", "chicken", 1, 1))
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

	// Draw order
	entities.push_back(new Environment("fenceBack", { 180, 176 }));
	entities.push_back(new Environment("fenceLeft", { 191, 205 }));
	entities.push_back(new Environment("fenceRight", { 788, 205 }));
	entities.push_back(new Player("player", { 512, 384 }));
	entities.push_back(new Environment("fenceFront", { 180, 576 })); // Must be drawn after Player
	
	chickenEntities.push_back(new Chicken("chicken", { 560, 384 }));

	for (auto& entity : entities)
	{
		m_vis->CreateSourceRect(entity->GetID());
	}

	for (auto& chicken : chickenEntities)
	{
		m_vis->CreateSourceRect(chicken->GetID());
	}

	return true;
}

void World::Run()
{
	HAPI_TColour clearScreenCol = HAPI_TColour::BLACK;
	m_vis->ClearToColour(clearScreenCol);

	while (HAPI.Update())
	{
		currentTime = clock();

		if (currentTime >= callTime + tickRate)
		{
			m_vis->ClearToColour(clearScreenCol);
			m_vis->DrawBackgroundSprite("background", 0, 0);

			// Draws entities every frame
			for (auto& entity : entities)
			{
				m_vis->DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);
				entity->Update();
			}

			for (auto& chicken : chickenEntities)
			{
				m_vis->DrawSprite(chicken->GetID(), chicken->GetPos().xPos, chicken->GetPos().yPos);
				chicken->Movement();
			}

			callTime = clock();
		}

		if (currentTime >= chickenCallTime + chickenRate)
		{
			for (auto& chicken : chickenEntities)
			{
				chicken->Handle();
			}

			chickenCallTime = clock();
		}
	}
}
