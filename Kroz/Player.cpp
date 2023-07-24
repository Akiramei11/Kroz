#include "Player.h"

Player::Player() {
	setName("Player");
	setDescription("A true Hero");
	setMaxHealth(13);
	setHealth(13);

}

void Player::look() {}

void Player::listInventory() {
	for (auto ents : elements) {
		ents.second->look();
	}
}

void Player::takeItem(Item* item) {
	if (item->is_pickable() and not isInventory(item)) {
		item->getParent()->removeElement(item);
		addElement(item);
	}
	else std::cout << "This is not pickable" << std::endl;
}

void Player::dropItem(Item* item) {
	if (item->is_pickable() and isInventory(item)) {
		removeElement(item);
		parent->addElement(item);
	}
	else std::cout << "Can't do this" << std::endl;
}

bool Player::isInventory(Entity* item) {
	auto it = elements.find(item->getName());
	if (it != elements.end()) return true;
	return false;
}