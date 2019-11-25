#pragma once
#include <iostream>
#include <vector>

class Visualisation;
class Entity;

class World
{
private:
	std::shared_ptr<Visualisation> m_vis;
	std::vector <Entity*> entities; // maybe make map??

public:
	World();
	~World();

	bool Initialise();
	bool LoadLevel();
	void Run();
};

