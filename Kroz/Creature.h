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
	void attack(Creature* creature, Item* weapon);
	void eatItem(Item* food);
	void drinkItem(Item* drink);
	void kill();

	void setMaxHealth(const int& maxH);
	void setHealth(const int& h);

	int getHealth();
	int getMaxHealth();

	Entity* deepSearch(const std::string& toSearch);
protected:
	int maxHealth = 10, health = maxHealth;
	int dmg = 1;
	bool raged = false;
	
};

