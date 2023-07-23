#pragma once
#include "Entity.h"

class Creature : public Entity
{
public:
	Creature() {};
	//Creature(std::ifstream& inputFile);

	void setMaxHealth(const int& maxH);
	void setHealth(const int& h);
private:
	int maxHealth = 10, health = maxHealth;
	int dmg = 1;

	
};

