#include "Creature.h"

//Creature::Creature(std::ifstream& inputFile) {
//}

void Creature::setMaxHealth(const int& maxH) {
    maxHealth = maxH;
}
void Creature::setHealth(const int& h) {
    health = h;
}

void Creature::moveToGateway(Gateway* gateway) {
    if (gateway->is_open()) {
        parent->removeElement(this);
        std::string dest = gateway->getDestination();
        parent->getParent()->getElement(dest)->addElement(this);
    }
    else std::cout << "This is closed" << std::endl;
}

void Creature::attack(Creature* creature) {

}
void Creature::eatItem(Item* food) {

}
void Creature::drinkItem(Item* drink) {

}