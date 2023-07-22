#include "Room.h"
#include <fstream>

Room::Room() {}

Room::Room(std::ifstream& inputFile) {
    std::string line;
    bool name = false;
    bool description = false;
    bool name = false;

    while (std::getline(inputFile, line)) {
        size_t pos = line.find_first_not_of(" \t");
        if (pos != std::string::npos) {
            line.erase(0, pos);
        }
        if (line.compare(0, std::string("name: ").length(), "name: ") == 0) {

        }
        else if (line.compare(0, std::string("description: ").length(), "description: ") == 0) {
        }
        else if (line.compare(0, std::string("parent: ").length(), "parent: ") == 0) {
        }
        else if (line.compare(0, std::string("Gateway").length(), "Gateway") == 0) {
            addElements(new Gateway(inputFile));
        }
        else if (line.compare(0, std::string("Item").length(), "Item") == 0) {
            addElements(new Item(inputFile));
        }
        else if (line.compare(0, std::string("Creature").length(), "Creature") == 0) {
            addElements(new Creature(inputFile));
        }
        else if (line.compare(0, std::string("Player").length(), "Player") == 0) {
            addElements();
        }
    }
}