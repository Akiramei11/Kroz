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
		delete parent; // Properly deallocate the previous object to avoid memory leak
	}
	parent = p;
}

void Entity::addElements(Entity* entity) {
	elements.push_back(entity);
}