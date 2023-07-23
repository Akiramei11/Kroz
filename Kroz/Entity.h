#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>

class Entity
{
public:
	Entity() : name("World"), description("A whole new World") {}
	Entity(const std::string& info);
	~Entity();

	void setName(const std::string& a);
	void setDescription(const std::string& a);
	void setParent(Entity* p);
	void addElements(Entity* entity);

	Entity* getElement(const std::string name);
	std::string getName();

	std::string getStringAfterColon(const std::string& input);
	bool stringToBool(const std::string& input);
private:
	std::string name;
	std::string description;

	Entity* parent = nullptr;
	std::list<Entity*> elements;
};

