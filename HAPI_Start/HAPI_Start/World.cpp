#include "World.h"
#include <HAPI_lib.h>
#include "Visualisation.h"
#include "Player.h"
#include "Environment.h"

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
	// Creating sprites
	if (!m_vis->CreateSprite("Data\\environment.png", "background", 1, 1)) // BACKGROUND MAKE ENTITY
		return false;
	if (!m_vis->CreateSprite("Data\\player.png", "player", 4, 4)) // Last 2 ints for sprite sheets
		return false;
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

	for (auto& entity : entities)
	{
		m_vis->CreateSourceRect(entity->GetID());
	}

	return true;
}

void World::Run()
{	
	HAPI_TColour clearScreenCol = HAPI_TColour::BLACK;
	m_vis->ClearToColour(clearScreenCol);

	while (HAPI.Update())
	{
		m_vis->ClearToColour(clearScreenCol);
		m_vis->DrawBackgroundSprite("background", 0, 0);

		for (auto& entity : entities)
		{
			m_vis->DrawSprite(entity->GetID(), entity->GetPos().xPos, entity->GetPos().yPos);
			entity->Update();
		}
	}
}
