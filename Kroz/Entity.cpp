#include "Entity.h"

Entity::Entity(const std::string& info) {}

Entity::~Entity() {
	for (Entity* entity : elements) {
		delete entity;
	}
	elements.clear();
	delete parent;
}

void Entity::setName(const std::string& a) {
	name = a;
}

void Entity::setDescription(const std::string& a) {
	description = a;
}

void Entity::setParent(Entity* p) {
	if (parent != nullptr) {
		delete parent;
	}
	parent = p;
}

void Entity::addElements(Entity* entity) {
	elements.push_back(entity);
	entity->setParent(this);
}

Entity* Entity::getElement(const std::string name) {
	auto it = elements.begin();
	while (it != elements.end()) {
		if ((*it)->getName() == name) return *it;
		std::advance(it, 1);
	}
}

std::string Entity::getName() {
	return name;
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