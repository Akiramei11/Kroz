#pragma once
#include "Creature.h"
class Player : public Creature
{
public:
	Player();

	void look() override;

	void takeItem(Item* item);
	void dropItem(Item* item);
	void throwItem(Item* item);
	void listInventory();
	void examineEntity(Entity* entity);
	void open(Gateway* gateway);
	void close(Gateway* gateway);

private:

};

