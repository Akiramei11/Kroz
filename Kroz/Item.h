#pragma once
#include "Entity.h"

enum ItemType {
	ARMOR = 0,
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
	ItemType type;
};

