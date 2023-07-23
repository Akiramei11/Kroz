#include "Room.h"
#include "Gateway.h"
#include "Item.h"
#include "NPC.h"
#include <fstream>

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
            addElements(new Gateway(inputFile));
        }
        else if (line.compare(0, std::string("Item").length(), "Item") == 0) {
            addElements(new Item(inputFile));
        }
        else if (line.compare(0, std::string("Creature").length(), "Creature") == 0) {
            addElements(new NPC(inputFile));
        }
        else if (line == "}") {
            break;
        }
    }
}
