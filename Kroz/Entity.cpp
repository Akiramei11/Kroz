#include "Entity.h"

Entity::Entity(const std::string& info) {}

Entity::~Entity() {
	for (auto entity : elements) {
		delete entity.second;
	}
	elements.clear();
	delete parent;
}

void Entity::look() {
	std::cout << name << ": " << description << std::endl;
	for (auto ents : elements) {
		ents.second->look();
	}
}

void Entity::setName(const std::string& a) {
	name = a;
}

void Entity::setDescription(const std::string& a) {
	description = a;
}

void Entity::setParent(Entity* p) {
	/*if (parent != nullptr) {
		delete parent;
	}*/
	parent = p;
}

void Entity::addElement(Entity* entity) {
	std::string entityName= entity->getName();
	elements[entityName] = entity;
	entity->setParent(this);
}

void Entity::removeElement(Entity* entity) {
	auto it = elements.find(entity->getName());
	if (it != elements.end()) {
		elements.erase(it);
	}
}

Entity* Entity::getElement(const std::string name) {
	return elements[name];
}

std::string Entity::getName() {
	return name;
}

Entity* Entity::getParent() {
	return parent;
}


std::string Entity::getStringAfterColon(const std::string& input) {
	size_t pos = input.find(": ");
	if (pos == std::string::npos) {
		return "";
	}
	return input.substr(pos + 2);
}

bool Entity::stringToBool(const std::string& input) {
	return (input == "true" || input == "1" || input == "yes" || input == "y" || input == "Y");
}