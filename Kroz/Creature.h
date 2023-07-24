#pragma once
#include "Entity.h"
#include "Item.h"
#include "Gateway.h"

class Creature : public Entity
{
public:
	Creature() {};
	//Creature(std::ifstream& inputFile);

	void moveToGateway(Gateway* gateway);
	void attack(Creature* creature);
	void eatItem(Item* food);
	void drinkItem(Item* drink);

	void setMaxHealth(const int& maxH);
	void setHealth(const int& h);
protected:
	int maxHealth = 10, health = maxHealth;
	int dmg = 1;

	
};

