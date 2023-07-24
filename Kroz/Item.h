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

	void look() override;
	Entity* deepSearch(const std::string& toSearch);

	void setOpen(const bool& state);

	bool is_pickable();
	ItemType getType();
	int getDmg();
	int getHealing();
private:
	bool pickable;
	ItemType type;
	bool open;
	bool locked;
	int dmg = 1;
	int healing;
};

