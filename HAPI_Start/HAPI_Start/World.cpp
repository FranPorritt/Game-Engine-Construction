#include <time.h>
#include <HAPI_lib.h>
#include <assert.h>

#include "World.h"
#include "Visualisation.h"
#include "Player.h"
#include "Chicken.h"
#include "Environment.h"
#include "SeedBox.h"

using namespace HAPISPACE;

World::World()
{
}

World::~World()
{
	for (auto& entity : entities)
	{
		delete entity;
	}
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

	// Draw order
	entities.push_back(new Environment("fenceBack", { 180, 176 }));
	entities.push_back(new Environment("fenceLeft", { 191, 205 }));
	entities.push_back(new Environment("fenceRight", { 788, 205 }));

	entities.push_back(new SeedBox("seedBox", { 220, 190 }));

	entities.push_back(new Player("player", { 512, 384 }));

	entities.push_back(new Environment("fenceFront", { 180, 576 })); // Must be drawn after Player


	chickenEntities.push_back(new Chicken("chicken", { 560, 384 }));
	chickenEntities.push_back(new Chicken("chicken1", { 430, 480 }));
	chickenEntities.push_back(new Chicken("chicken2", { 650, 290 }));
	chickenEntities.push_back(new Chicken("chicken3", { 390, 384 }));

	for (auto& entity : entities)
	{
		m_vis->CreateSourceRect(entity->GetID());
		entity->CreateRect(m_vis->GetSpriteHeight(entity->GetID()), m_vis->GetSpriteWidth(entity->GetID()));
	}

	for (auto& chicken : chickenEntities)
	{
		m_vis->CreateSourceRect(chicken->GetID());
		chicken->CreateRect(m_vis->GetSpriteHeight(chicken->GetID()), m_vis->GetSpriteWidth(chicken->GetID()));
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
				vector2<int> currentPos = entity->GetPos();
				entity->Update();

				for (auto& entity2 : entities)
				{
					// Check entitys aren't same side, or some variable
					if ((entity2 != entity) && (entity2->GetSide() != entity->GetSide())) 
					{
						if (entity->Collision(*entity, *entity2))
						{
							entity->SetPos(currentPos);
							
							if (entity->GetSide() == ESide::eSidePlayer)
							{
								static_cast<Player*>(entity)->Interaction(*entity2);
							}
						}
					}
				}

				m_vis->DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);
			}

			for (auto& chicken : chickenEntities)
			{
				m_vis->DrawSprite(chicken->GetID(), chicken->GetPos().xPos, chicken->GetPos().yPos);
				chicken->Movement();
			}

			callTime = clock();
		}

		// Controls switch between wandering and idle chicken states		
		if (currentTime >= chickenCallTime + chickenRate)
		{
			for (auto& chicken : chickenEntities)
			{
				if (currentTime >= chickenCallTime + chicken->GetRate())
				{
					chicken->Handle();
					chickenCallTime = clock();
				}
			}
		}
	}
}
