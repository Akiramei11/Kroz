#pragma once
#include <string>
#include <vector>
#include <list>

class Entity
{
public:
	Entity(){}
	Entity(const std::string& info);
	~Entity();

	void setName(const std::string& a);
	void setDescription(const std::string& a);
	void setParent(Entity* p);
	void addElements(Entity* entity);
private:
	std::string name;
	std::string description;

	Entity* parent = nullptr;
	std::list<Entity*> elements;
};

