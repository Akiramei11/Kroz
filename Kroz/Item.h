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
	void unlock(Entity* key) override;

	void setOpen(const bool& state);

	bool is_pickable();
	bool is_open();
	ItemType getType();
	int getDmg();
	int getHealing();
	std::string getKey();
private:
	bool pickable;
	ItemType type;
	bool open;
	bool locked;
	std::string key;
	int dmg = 1;
	int healing;
};

