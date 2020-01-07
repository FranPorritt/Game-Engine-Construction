#pragma once
#include "Entity.h"

class Projectile :	public Entity
{
protected:
	EDirection playerDir = EDirection::eStop; // Players last direction other than stop

public:
	Projectile(const std::string& graphicIDArg, vector2<int> positionArg);
	~Projectile();

	void Direction() override final;

	void SetPos(vector2<int>& pos);
	void SetFlag(const int& value) { activeFlag = value; };
	void SetDir(EDirection direction);

	bool GetFlag() const { return activeFlag; };
};

