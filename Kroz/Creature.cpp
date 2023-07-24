#include "Creature.h"

//Creature::Creature(std::ifstream& inputFile) {
//}

void Creature::setMaxHealth(const int& maxH) {
    maxHealth = maxH;
}
void Creature::setHealth(const int& h) {
    if (h > maxHealth) {
        health = maxHealth;
    }
    else health = h;
}

int Creature::getHealth() {
    return health;
}

int Creature::getMaxHealth() {
    return maxHealth;
}


void Creature::moveToGateway(Gateway* gateway) {
    if (gateway->is_open()) {
        parent->removeElement(this);
        std::string dest = gateway->getDestination();
        parent->getParent()->getElement(dest)->addElement(this);
    }
    else std::cout << "This is closed" << std::endl;
}

void Creature::attack(Creature* creature, Item* weapon) {
    int currentHealth = creature->getHealth();
    int weaponDmg = weapon->getDmg();
    if (currentHealth - weaponDmg > 0) {
        creature->setHealth(currentHealth - weaponDmg);
    }
    else creature->kill();
}
void Creature::eatItem(Item* food) {

}
void Creature::drinkItem(Item* drink) {

}

void Creature::kill() {
    for (auto it = elements.begin(); it != elements.end(); ) {
        Entity* element = it->second;
        it = elements.erase(it);
        parent->addElement(element);
    }
    parent->removeElement(this);
    parent = nullptr;
}

Entity* Creature::deepSearch(const std::string& toSearch) {
    if (name == toSearch) return this;
    for (const auto& element : elements) {
        if (Entity* elem = element.second->deepSearch(toSearch)) {
            return elem;
        }
    }
    return nullptr;
}