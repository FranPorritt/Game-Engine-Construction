#include "World.h"
#include <HAPI_lib.h>
#include "Visualisation.h"
#include "Entity.h"
#include "Player.h"

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
	if (!m_vis->CreateSprite("Data\\Leah.png", "player", 4, 4))
		return false;

	m_vis->CreateSourceRect("player");

	entities.push_back(new Player("player"));

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
		m_vis->DrawSprite("player", entities[0]->GetPos().xPos, entities[0]->GetPos().yPos);

		for (auto& entity : entities)
		{
			entity->Update();
		}
	}
}
