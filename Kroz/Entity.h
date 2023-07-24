#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>

class Entity
{
public:
	Entity() : name("World"), description("A whole new World") {}
	Entity(const std::string& info);
	virtual ~Entity();

	virtual void look();
	void examine();
	virtual Entity* deepSearch(const std::string& toSearch);

	void setName(const std::string& a);
	void setDescription(const std::string& a);
	void setParent(Entity* p);
	void addElement(Entity* entity);
	void removeElement(Entity* entity);

	Entity* getElement(const std::string name);
	
	std::string getName();
	Entity* getParent();

	std::string getStringAfterColon(const std::string& input);
	bool stringToBool(const std::string& input);
protected:
	std::string name;
	std::string description;

	Entity* parent = nullptr;
	std::map<std::string, Entity*> elements;
};

