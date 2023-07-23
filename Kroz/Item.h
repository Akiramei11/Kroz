#pragma once
#include "Entity.h"

enum ItemType {
	ITEM,
	WEAPON,
	TOOL,
	FOOD,
	DRINK,
	DOCUMENT,
	CONTAINER
};

class Item : public Entity
{
public:
	Item(std::ifstream& inputFile);
private:
	bool pickable;
	ItemType type;
	bool open;
	bool locked;
	int dmg = 1;
};

