#include "Room.h"
#include "Gateway.h"
#include "Item.h"
#include "NPC.h"
#include <fstream>

Room::Room() {

}

Room::~Room() {

}

Room::Room(std::ifstream& inputFile) {
    std::string line;

    while (std::getline(inputFile, line)) {
        size_t pos = line.find_first_not_of(" \t");
        if (pos != std::string::npos) {
            line.erase(0, pos);
        }
        if (line.compare(0, std::string("name: ").length(), "name: ") == 0) {
            setName(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("description: ").length(), "description: ") == 0) {
            setDescription(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("Gateway").length(), "Gateway") == 0) {
            addElement(new Gateway(inputFile));
        }
        else if (line.compare(0, std::string("Item").length(), "Item") == 0) {
            addElement(new Item(inputFile));
        }
        else if (line.compare(0, std::string("Creature").length(), "Creature") == 0) {
            addElement(new NPC(inputFile));
        }
        else if (line == "}") {
            break;
        }
    }
}

Entity* Room::getGateway(const std::string& dest) {
    return (Gateway*)getElement(dest);
}

Entity* Room::getGatewayDirection(const std::string& dest) {
    for (const auto& element : elements) {
        Gateway* gate = dynamic_cast<Gateway*>(element.second);
        if (gate && gate->getDirection() == dest) {
            return gate;
        }
    }
    return nullptr;
}

Entity* Room::deepSearch(const std::string& toSearch) {
    for (const auto& element : elements) {
        if (Entity* elem = element.second->deepSearch(toSearch)) {
            return elem;
        }
    }
    return nullptr;
}

void Room::look() {
    std::cout << name << std::endl << description << std::endl;
    for (auto ents : elements) {
        ents.second->look();
    }
}
